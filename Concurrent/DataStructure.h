//
// Created by ning on 2018/10/25.
//

#ifndef INTERVIEW_CPP_DATASTRUCTURE_H
#define INTERVIEW_CPP_DATASTRUCTURE_H

#include <exception>
#include <stack>
#include <queue>
#include <boost/thread/thread.hpp>

namespace Concurrent {
	struct empty_stack : std::exception {
		const char *what() const throw();
	};

	template<typename T>
	class threadsafe_stack {
	public:
		threadsafe_stack() {}

		threadsafe_stack(const threadsafe_stack &other) {
			std::lock_guard<std::mutex> lock(other.m);
			data = other.data;
		}

		threadsafe_stack &operator=(const threadsafe_stack &) = delete;

		void push(T new_value) {
			std::lock_guard<std::mutex> lock(m);
			data.push(std::move(new_value));    // 1
		}

		std::shared_ptr<T> pop() {
			std::lock_guard<std::mutex> lock(m);
			if (data.empty())
				throw empty_stack();  // 2
			std::shared_ptr<T> const res(std::make_shared<T>(std::move(data.top())));
			data.pop();
			return res;
		}

		void pop(T &value) {
			std::lock_guard<std::mutex> lock(m);
			if (data.empty())
				throw empty_stack();
			value = std::move(data.top());  // 5
			data.pop();
		}

		bool empty() const {
			std::lock_guard<std::mutex> lock(m);
			return data.empty();
		}

	private:
		std::stack<T> data;
		mutable std::mutex m; // mutable
	};

	template<typename T>
	class threadsafe_queue {
	public:
		threadsafe_queue() {}

		void push(T new_value) {
			std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
			std::lock_guard<std::mutex> lock(mut);
			data_queue.push(data);
			data_cond.notify_one(); //
		}

		void wait_and_pop(T &value) {
			std::unique_lock<std::mutex> lock(mut);
			data_cond.wait(lock, [this] { return !data_queue.empty(); });
			value = std::move(*data_queue.front());
			data_queue.pop();
		}

		std::shared_ptr<T> wait_and_pop() {
			std::unique_lock<std::mutex> lock(mut);
			data_cond.wait(lock, [this] { return !data_queue.empty(); });
			std::shared_ptr<T> res = data_queue.front();
			data_queue.pop();
			return res;
		}

		bool try_pop(T &value) {
			std::lock_guard<std::mutex> lock(mut);
			if (data_queue.empty())
				return false;
			value = std::move(data_queue.front());
			data_queue.pop();
			return true;
		}

		std::shared_ptr<T> try_pop() {
			std::lock_guard<std::mutex> lock(mut);
			if (data_queue.empty())
				return std::shared_ptr<T>();
			std::shared_ptr<T> res = data_queue.front();
			data_queue.pop();
			return res;
		}

		bool empty() const {
			std::lock_guard<std::mutex> lock(mut);
			return data_queue.empty();
		}

	private:
		mutable std::mutex mut;
		std::queue<std::shared_ptr<T>> data_queue;
		std::condition_variable data_cond;
	};

	template<typename T>
	class queueLink {
	public:
		queueLink() : head(new node), tail(head.get()) {}

		queueLink(const queueLink &other) = delete;

		queueLink &operator=(const queueLink &) = delete;

		std::shared_ptr<T> try_pop() {
			std::unique_ptr<node> old_head = pop_head();
			return old_head ? old_head->data : std::shared_ptr<T>();
		}

		void push(T new_value) {
			std::shared_ptr<T> new_data = (std::make_shared<T>(std::move(new_value)));
			std::unique_ptr<node> p(new node);
			node *const new_tail = p.get();

			std::lock_guard<std::mutex> tail_lock(tail_mutex);
			tail->data = new_data;
			tail->next = std::move(p);
			tail = new_tail;
		}

	private:
		struct node {
			std::shared_ptr<T> data;
			std::unique_ptr<node> next;

			node() {}

			node(T data_) : data(std::move(data_)) {}
		};

		std::mutex head_mutex;
		std::mutex tail_mutex;
		std::unique_ptr<node> head; // 1
		node *tail;
		std::condition_variable data_cond;

		node *get_tail() {
			std::lock_guard<std::mutex> tail_lock(tail_mutex);
			return tail;
		}

		std::unique_ptr<node> pop_head() {
			std::lock_guard<std::mutex> head_lock(head_mutex);

			if (head.get() == get_tail())
				return nullptr;

			std::unique_ptr<node> old_head = std::move(head);
			head = std::move(old_head->next);
			return old_head;
		}
	};

	template<typename Key, typename Value, typename Hash=std::hash<Key>>
	class threadsafe_lookup_table {
	public:
		typedef Key key_type;
		typedef Value mapped_type;
		typedef Hash hash_type;

	private:
		class bucket_type {
		private:
			typedef std::pair<Key, Value> bucket_value;
			typedef std::list<bucket_value> bucket_data;    // list
			typedef typename bucket_data::iterator bucket_iterator;

			bucket_data data;

			mutable boost::shared_mutex mutex;

			bucket_iterator find_entry_for(Key const &key) const {
				return std::find_if(data.begin(), data.end(), [&](bucket_value const &item) {
					return item.first == key;
				});
			}

		public:
			Value value_for(Key const &key, Value const &default_value) const {
				boost::shared_lock<boost::shared_mutex> lock(mutex);

				bucket_iterator const found_entry = find_entry_for(key);
				return (found_entry == data.end()) ? default_value : found_entry->second;
			}

			void add_or_update_mapping(Key const &key, Value const &value) {

				std::unique_lock<boost::shared_mutex> lock(mutex);
				bucket_iterator const found_entry = find_entry_for(key);

				if (data.end() == found_entry)
					data.push_back(bucket_value(key, value));
				else
					found_entry->second = value;
			}

			void remove_mapping(Key const &key) {
				std::unique_lock<boost::shared_mutex> lock(mutex);
				bucket_iterator const found_entry = find_entry_for(key);
				if (found_entry != data.end())
					data.erase(found_entry);
			}
		};

		std::vector<std::unique_ptr<bucket_type>> buckets;
		Hash hasher;

		bucket_type &get_bucket(Key const &key) const {
			std::size_t const bucket_index = hasher(key) % buckets.size();
			return *buckets[bucket_index];
		}
	};


}


#endif //INTERVIEW_CPP_DATASTRUCTURE_H
