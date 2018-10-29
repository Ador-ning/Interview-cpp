//
// Created by ning on 2018/10/26.
//

#ifndef INTERVIEW_CPP_DATASTRUCTURENOLOCK_H
#define INTERVIEW_CPP_DATASTRUCTURENOLOCK_H

#include <list>
#include <thread>
#include <future>
#include <vector>
#include <atomic>
#include <numeric>

namespace Concurrent {
	class join_threads {
	public:
		join_threads(std::vector<std::thread> &threads_) : threads(threads_) {}

		~join_threads() {
			for (auto thread:threads) {
				if (thread.joinable())
					thread.join();
			}
		}

	private:
		std::vector<std::thread> &threads;
	};

	// 线程并发安全栈
	template<typename T>
	class thread_safe_stack {
	public:
		std::shared_ptr<T> pop() {
			return std::shared_ptr<T>();
		}

		void push(std::shared_ptr<T> &T) {

		}
	};

	// 使用栈的并行快速排序算法 -- 等待数据快排序
	template<typename T>
	struct sorter {
		// data chunk
		struct chunk_to_sort {
			std::list<T> data;
			std::promise<std::list<T>> promise;
		};

		thread_safe_stack<chunk_to_sort> chunks;    // 2    栈上简单的存储
		std::vector<std::thread> threads;   // 3  设置线程
		unsigned const max_thread_count;
		std::atomic<bool> end_of_data;

		sorter() : max_thread_count(std::thread::hardware_concurrency() - 1), end_of_data(false) {}

		~sorter() {     // 4    清理线程
			end_of_data = true;     // 5    设置标志
			for (unsigned i = 0; i < threads.size(); ++i) {
				if (threads[i].joinable())
					threads[i].join();      // 6
			}
		}

		void try_sort_chunk() {
			std::shared_ptr<chunk_to_sort> chunk = chunks.pop();    // 7    栈上弹出数据块
			if (chunk)
				sort_chunk(chunk);  // 8    排序
		}

		// 对数据进行划分
		std::list<T> do_sort(std::list<T> &chunk_data) {
			if (chunk_data.empty())
				return chunk_data;

			std::list<T> result;
			result.splice(result.begin(), chunk_data, chunk_data.begin());  // divide

			T const &partition_val = *result.begin();
			// 10
			typename std::list<T>::iterator divide_point = std::partition(chunk_data.begin(),
			                                                              chunk_data.end(),
			                                                              [&](T const &val) {
				                                                              return val < partition_val;
			                                                              });

			chunk_to_sort new_lower_chunk;
			new_lower_chunk.data.splice(new_lower_chunk.data.end(),
			                            chunk_data, chunk_data.begin(), divide_point);

			std::future<std::list<T>> new_lower = new_lower_chunk.promise.get_future();
			// chunks.push(std::move(new_lower_chunk));    // 11   将产生的数据块 push到栈上

			if (threads.size() < max_thread_count)      // 12   产生新线程
				threads.push_back(std::thread(&sorter<T>::sort_thread, this));

			std::list<T> new_higher(do_sort(chunk_data));
			result.splice(result.end(), new_higher);

			while (new_lower.wait_for(std::chrono::seconds(0)) != std::future_status::ready) // 13  等待其他线程
				try_sort_chunk();   // 14

			result.splice(result.begin(), new_lower.get());
			return result;
		}

		void sort_chunk(std::shared_ptr<chunk_to_sort> const &chunk) {
			chunk->promise.set_value(do_sort(chunk->data)); // 15   将结果存放在 promise 中
		}

		void sort_thread() {
			while (!end_of_data) {  // 16   还有数据时
				try_sort_chunk();   // 17   尝试从栈上获取需要排序的数据块
				std::this_thread::yield();  // 18 在循环检查中，也要给其他线程机会
			}
		}
	};

	// Test
	template<typename T>
	std::list<T> parallel_quick_sort1(std::list<T> input) {     // 19
		if (input.empty())
			return input;

		sorter<T> s;
		return s.do_sort(input);    // 20
	}

	// std::async 实现并行 std::for_each
	template<typename Iterator, typename Func>
	void parallel_for_each(Iterator first, Iterator last, Func f) {
		unsigned long const length = std::distance(first, last);

		if (!length)
			return;

		unsigned long const min_per_thread = 25;

		if (length < (2 * min_per_thread))
			std::for_each(first, last, f);  // one thread
		else {
			Iterator const mid_point = first + length / 2;
			std::future<void> first_half = std::async(&parallel_for_each<Iterator, Func>, first, mid_point,
			                                          f);     // 2  异步执行部分
			parallel_for_each(mid_point, last, f);  // 3 剩余直接运行
			first_half.get();   // 4
		}
	}


	// std::async 实现并行 std::find
	template<typename Iterator, typename MatchType>
	Iterator parallel_find_impl(Iterator first, Iterator last, MatchType match, std::atomic<bool> &done) {
		try {
			unsigned long const length = std::distance(first, last);
			unsigned long const min_per_thread = 25;
			if (length < (2 * min_per_thread)) {
				for (; (first != last && !done.load()); ++first) {
					if (*first == match) {
						done = true;
						return first;
					}
				}
				return last;    // in the end
			} else {
				Iterator const mid_point = first + length / 2;
				std::future<Iterator> async_result = std::async(&parallel_find_impl<Iterator, MatchType>, mid_point,
				                                                last, match, std::ref(done));

				Iterator const direct_result = parallel_find_impl(first, last, match, done);
				return (direct_result == mid_point) ? async_result.get() : direct_result;   // return thre first noe
			}
		} catch (...) {
			done = true;
			throw;
		}
	}

	template<typename Iterator, typename MatchType>
	Iterator parallel_find(Iterator first, Iterator last, MatchType match) {
		std::atomic<bool> done(false);
		return parallel_find_impl(first, last, match, done);
	}

	// 并行实现 std::partial_sum        [1, 2, 3, 4, 5] --> [1, 3, 6, 10, 15]
	// 使用划分的方式来并行的计算部分和
	template<typename Iterator>
	void parallel_partial_sum(Iterator first, Iterator last) {
		typedef typename Iterator::value_type value_type;

		struct process_chunk { // 1
			void operator()(Iterator begin, Iterator last, std::future<value_type> *previous_end_value,
			                std::promise<value_type> *end_value) {
				try {
					Iterator end = last;
					++end;
					std::partial_sum(begin, end, begin);    // 2
					if (previous_end_value) {    // 3
						value_type &addend = previous_end_value->get(); // 4
						*last += addend; // 5
						if (end_value)
							end_value->set_value(*last); // 6

						std::for_each(begin, last, [addend](value_type &item) {
							item += addend;
						}); // 7
					} else if (end_value) {
						end_value->set_value(*last); // 8
					}
				} catch (...) { // 9
					if (end_value)
						end_value->set_value(std::current_exception());
					else
						throw;
				}
			}
		};

		unsigned long const length = std::distance(first, last);

		if (!length)
			return last;

		unsigned long const min_per_thread = 25; // 12
		unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;
		unsigned long const hardware_threads = std::thread::hardware_concurrency();
		unsigned long const num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
		unsigned long const block_size = length / num_threads;

		// typedef typename Iterator::value_type value_type;

		std::vector<std::thread> threads(num_threads - 1); // 13
		std::vector<std::promise<value_type >> end_values(num_threads - 1); // 14
		std::vector<std::future<value_type >> previous_end_values;  // 15
		previous_end_values.reserve(num_threads - 1); // 16
		join_threads joiner(threads);

		Iterator block_start = first;
		for (unsigned long i = 0; i < (num_threads - 1); ++i) {
			Iterator block_last = block_start;
			std::advance(block_last, block_size - 1);   // 17
			threads[i] = std::thread(process_chunk(), block_start, block_last, (i != 0) ?
			                                                                   &previous_end_values[i - 1] : 0,
			                         &end_values[i]);
			block_start = block_last;
			++block_start;  // 19
			previous_end_values.push_back(end_values[i].get_future());  // 20
		}

		Iterator final_element = block_start;
		std::advance(final_element, std::distance(block_start, last) - 1);  // 21
		process_chunk()(block_start, final_element,
		                (num_threads > 1) ? &previous_end_values.back() : 0, 0);
	}
};

#endif //INTERVIEW_CPP_DATASTRUCTURENOLOCK_H
