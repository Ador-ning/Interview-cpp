//
// Created by ning on 2018/10/28.
//

#ifndef INTERVIEW_CPP_THREADPOOL_H
#define INTERVIEW_CPP_THREADPOOL_H

#include <thread>
#include <atomic>
#include <functional>
#include "DataStructure.h"
#include "DataStructureNoLock.h"

namespace Concurrent {

	using namespace Concurrent;

	// 1. 简单的线程池
	class thread_pool {
	public:
		thread_pool() : done(false), joiner(threads) {
			// 8
			unsigned const thread_count = std::thread::hardware_concurrency();
			try {
				for (unsigned i = 0; i < thread_count; ++i) {
					threads.push_back(std::thread(&thread_pool::worker_thread, this)); // 9
				}
			} catch (...) {
				done = true;    // 10
				throw;
			}
		}

		~thread_pool() {
			done = true;
		}

		template<typename FunctionType>
		void submit(FunctionType f) {
			work_queue.push(std::function<void()>(f));  // 12
		}

	private:
		void worker_thread() {
			while (!done) { // 4
				std::function<void()> task;
				if (work_queue.try_pop(task)) { // 5
					task(); // 6
				} else
					std::this_thread::yield();  // 7
			}
		}

		std::atomic_bool done;
		threadsafe_queue<std::function<void()>> work_queue;     // 1
		std::vector<std::thread> threads;   // 2
		join_threads joiner; // 3
	};

	// 2. 可等待任务的线程
	class function_wrapper {
	public:
		template<typename F>
		function_wrapper(F &&f):impl(new impl_type<F>(std::move(f))) {}

		function_wrapper(function_wrapper &&other) : impl(std::move(other.impl)) {}

		function_wrapper &operator=(function_wrapper &&other) {
			impl = std::move(other.impl);
			return *this;
		}

		function_wrapper(const function_wrapper &) = delete;

		function_wrapper(function_wrapper &) = delete;

		function_wrapper() = default;

		function_wrapper &operator=(const function_wrapper &) = delete;

		void operator()() {
			impl->call();
		}

	private:
		struct impl_base {
			virtual void call() =0;

			virtual ~impl_base() {}
		};

		std::unique_ptr<impl_base> impl;

		template<typename F>
		struct impl_type : impl_base {
			F f;

			impl_type(F &&f_) : (std::move(f_)) {}

			void call() {
				f();
			}
		};
	};

	class thread_pool2 {
	public:
		thread_pool2() : done(false), joiner(threads) {
			unsigned const thread_count = std::thread::hardware_concurrency();
			try {
				for (unsigned i = 0; i < thread_count; ++i) {
					threads.push_back(std::thread(&thread_pool2::worker_thread, this)); // 9
				}
			} catch (...) {
				done = true;    // 10
				throw;
			}
		}

		~thread_pool2() {
			done = true;
		}

		template<typename FunctionType>
		std::future<typename std::result_of<FunctionType()>> submit(FunctionType f) {
			typedef typename std::result_of<FunctionType()> result_type;  // 2

			std::packaged_task<result_type()> task(std::move(f));   // 3
			std::future<result_type> res(task.get_future());    // 4

			work_queue.push(std::move(task));   // 5
			return res;
		}

		void run_pending_task() {
			function_wrapper task;
			if (work_queue.try_pop(task))
				task();
			else
				std::this_thread::yield();
		}

	private:
		void worker_thread() {
			while (!done) { // 4
				function_wrapper task;
				if (work_queue.try_pop(task)) { // 5
					task(); // 6
				} else
					std::this_thread::yield();  // 7
			}
		}

		std::atomic_bool done;
		threadsafe_queue<function_wrapper> work_queue;
		std::vector<std::thread> threads;
		join_threads joiner;
	};

	// 3. parallel_accumulate  using thread_pool
	template<typename Iterator, typename T>
	T accumulate_block() {
		return T();
	}

	template<typename Iterator, typename T>
	T parallel_accumulate_threadPool(Iterator first, Iterator last, T init) {
		unsigned long const length = std::distance(first, last);

		if (!length)
			return init;

		unsigned long const block_size = 50;
		unsigned long const num_blocks = (length + block_size - 1) / block_size;    // 1

		std::vector<std::future<T>> futures(num_blocks - 1);
		thread_pool2 pool;

		Iterator block_start = first;
		for (unsigned i = 0; i < (num_blocks - 1); ++i) {
			Iterator block_end = block_start;
			std::advance(block_end, block_size);
			futures[i] = pool.submit(accumulate_block<Iterator, T>());  // 2    the bound of computing??
			block_start = block_end;    // submit parameters??
		}

		T last_result = accumulate_block<Iterator, T>()(block_start, last);

		T result = init;
		for (unsigned j = 0; j < (num_blocks - 1); ++j) {
			result += futures[j].get();
		}
		result += last_result;
		return result;
	}

	// 4. quick sort using thread_pool
	template<typename T>
	struct sorter_threadPool {
		thread_pool2 pool;

		std::list<T> do_sort(std::list<T> &chunk_data) {
			if (chunk_data.empty())
				return chunk_data;

			std::list<T> result;
			result.splice(result.begin(), chunk_data, chunk_data.begin());
			T const &partition_val = *result.begin();

			typename std::list<T>::iterator divide_point = std::partition(chunk_data.begin(), chunk_data.end(),
			                                                              [&](T const &val) {
				                                                              return val < partition_val;
			                                                              });
			std::list<T> new_lowe_chunk;
			new_lowe_chunk.splice(new_lowe_chunk.end(), chunk_data, chunk_data.begin(), divide_point);
			/*
			 std::future<std::list<T>> new_lower = pool.submit(
					std::bind(&sorter::do_sort, this, std::move(new_lowe_chunk)));

			 std::future<std::list<T>> new_higher(do_sort(chunk_data));

			result.splice(result.end(), new_higher.get());

			while (!new_higher.wait_for(std::chrono::seconds(0)) ==
			       std::future_status::ready)
				pool.run_pending_task();

			result.splice(result.begin(), new_higher.get());
			 */     // type not match
			return result;
		}
	};

	template<typename T>
	std::list<T> parallel_quick_sort_threadPool(std::list<T> input) {
		if (input.empty())
			return input;
		sorter_threadPool<T> s;

		return s.do_sort(input);
	}

	// 5. 具有本地任务队列
	class thread_pool3 {
	public:
		thread_pool3() : done(false), joiner(threads) {
			unsigned const thread_count = std::thread::hardware_concurrency();
			try {
				for (unsigned i = 0; i < thread_count; ++i) {
					threads.push_back(std::thread(&thread_pool3::worker_thread, this));
				}
			} catch (...) {
				done = true;
				throw;
			}
		}

		~thread_pool3() {
			done = true;
		}

		template<typename Functype>
		std::future<typename std::result_of<Functype()>> submit(Functype f) {
			typedef typename std::result_of<Functype()> result_type;
			std::packaged_task<result_type()> task(f);
			std::future<result_type> res(task.get_future());

			if (local_work_queue)
				local_work_queue->push(std::move(task));
			else
				pool_work_queue.push(std::move(task));
			return res;
		}

	private:
		threadsafe_queue<function_wrapper> pool_work_queue;

		typedef std::queue<function_wrapper> local_queue_type; // 1
		static thread_local std::unique_ptr<local_queue_type> local_work_queue; // 2
		std::atomic_bool done;
		std::vector<std::thread> threads;
		join_threads joiner;

		void worker_thread() {
			local_work_queue.reset(new local_queue_type);   // 3
			while (!done) {
				run_pending_task();
			}
		}

		void run_pending_task() {
			function_wrapper task;

			if (local_work_queue && !local_work_queue->empty()) {   // 6
				task = std::move(local_work_queue->front());
				local_work_queue->pop();
				task();
			} else if (pool_work_queue.try_pop(task))   // 7
				task();
			else
				std::this_thread::yield();
		}
	};

	// 6. 窃取任务 --> 为了让没有任务的线程能从其他的任务队列中获取任务
	class work_stealing_queue {
	public:
		typedef function_wrapper data_type;

		work_stealing_queue() {}

		work_stealing_queue(const work_stealing_queue &) = delete;

		work_stealing_queue &operator=(const work_stealing_queue &) = delete;

		void push(data_type data) {
			std::lock_guard<std::mutex> lock(mutex);
			queue.push_front(std::move(data));
		}

		bool empty() const {
			return queue.empty();
		}

		bool try_pop(data_type &res) {
			std::lock_guard<std::mutex> lock(mutex);
			if (queue.empty())
				return false;
			res = std::move(queue.front());
			queue.pop_front();
			return true;
		}

		bool try_steal(data_type &res) {
			std::lock_guard<std::mutex> lock(mutex);
			if (queue.empty())
				return false;
			res = std::move(queue.back());
			queue.pop_back();
			return true;
		}

	private:
		std::deque<data_type> queue;
		mutable std::mutex mutex;
	};

	class thread_pool4 {
	public:
		typedef function_wrapper task_type;

		thread_pool4() : done(false), joiner(threads) {
			unsigned const thread_count = std::thread::hardware_concurrency();

			try {
				for (unsigned i = 0; i < thread_count; ++i) {
					queues.push_back(std::unique_ptr<work_stealing_queue>(new work_stealing_queue));
					threads.push_back(std::thread(&thread_pool4::worker_thread, this, i));
				}
			} catch (...) {
				done = true;
				throw;
			}
		}

		~thread_pool4() {
			done = true;
		}

		template<typename FunctionType>
		std::future<typename std::result_of<FunctionType()>> submit(FunctionType f) {
			typedef typename std::result_of<FunctionType()> result_type;
			std::packaged_task<result_type()> task(f);
			std::future<result_type> res(task.get_future());

			if (local_work_queue)
				local_work_queue->push(std::move(task));
			else
				pool_work_queue.push(std::move(task));
			return res;
		}

		void run_pending_task() {
			task_type task;
			if (pop_task_from_local_queue(task) || pop_task_from_pool_queue(task) ||
			    pop_task_from_other_thread_queue(task))
				task();
			else
				std::this_thread::yield();
		}

	private:
		std::atomic_bool done;
		threadsafe_queue<task_type> pool_work_queue;
		std::vector<std::unique_ptr<work_stealing_queue>> queues;   // 1
		std::vector<std::thread> threads;
		join_threads joiner;
		static thread_local work_stealing_queue *local_work_queue; // 2
		static thread_local unsigned my_index;

		void worker_thread(unsigned my_index_) {
			my_index = my_index_;
			local_work_queue = queues[my_index].get();  // 3
			while (!done)
				run_pending_task();
		}

		bool pop_task_from_local_queue(task_type &task) {
			return local_work_queue && local_work_queue->try_pop(task);
		}

		bool pop_task_from_pool_queue(task_type &task) {
			return pool_work_queue.try_pop(task);
		}

		bool pop_task_from_other_thread_queue(task_type &task) {
			for (unsigned i = 0; i < queues.size(); ++i) {
				unsigned const index = (my_index + i + 1) % queues.size();
				if (queues[index]->try_steal(task))
					return true;
			}
			return false;
		}
	};
}

#endif //INTERVIEW_CPP_THREADPOOL_H
