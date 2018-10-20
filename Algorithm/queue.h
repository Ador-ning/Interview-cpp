//
// Created by ning on 2018/5/31.
//

#ifndef INTERVIEW_CPP_QUEUE_H
#define INTERVIEW_CPP_QUEUE_H

#include <iostream>
#include <queue>
#include <exception>
#include <vector>

using namespace std;

namespace Algorithm {
//面试52：队列的最大值

/*
 * 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值
 * 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
 * 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}
 */
// 解法1
	vector<int> MaxInWindows(const vector<int> &num, unsigned int size) {
		vector<int> maxInWindows;

		if (num.size() >= size && size >= 1) {
			deque<int> index;

			for (unsigned int i = 0; i < size; ++i) {
				while (!index.empty() && num[i] >= num[index.back()])
					index.pop_back();

				index.push_back(i);
			}

			for (unsigned int i = size; i < num.size(); i++) {
				maxInWindows.push_back(num[index.front()]);

				while (!index.empty() && num[i] >= num[index.back()])
					index.pop_back();
				if (!index.empty() && index.front() <= (int) (i - size))
					index.pop_front();

				index.push_back(i);
			}
			maxInWindows.push_back(num[index.front()]);
		}

		return maxInWindows;
	}


// 解法2
	template<typename T>
	class QueueWithMax {
	public:
		QueueWithMax() : currentIndex(0) {}

		// push bach
		void push_back(T number) {
			//
			while (!maximums.empty() && number >= maximums.back().number)
				maximums.pop_back();

			InternalData internalData = {number, currentIndex};
			data.push_back(internalData);
			maximums.push_back(internalData);

			++currentIndex;
		}

		// pop front
		void pop_front() {
			if (maximums.empty())
				throw new exception("queue is empty.");

			if (maximums.front().index == data.front().index)
				maximums.pop_front();

			data.pop_front();
		}

		T max() const {
			if (maximums.empty())
				throw new exception("queue is empty.");
			return maximums.front().number;
		}

	private:
		struct InternalData {
			T number;
			int index;
		};
		deque<InternalData> data;
		deque<InternalData> maximums;
		int currentIndex;
	};

// Test
}
#endif //INTERVIEW_CPP_QUEUE_H
