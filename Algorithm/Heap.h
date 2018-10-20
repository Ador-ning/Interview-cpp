//
// Created by ning on 2018/7/1.
//

#ifndef INTERVIEW_CPP_HEAP_H
#define INTERVIEW_CPP_HEAP_H

#include <iostream>

using namespace std;

namespace Algorithm {
	const int maxn = 100;
	int heap[maxn], N = 10; // i - 2i - (2i+1)

// 大顶堆  low--待调整结点， high--heap边界
	void downAdjust(int low, int high) {
		int i = low;
		int j = 2 * i; // i为调整结点， 2i 为其左孩子

		while (j <= high) { // 存在左孩子结点
			if (j + 1 <= high && heap[j + 1] > heap[j]) // 存在右孩子，且右孩子值大于左孩子
				j = j + 1;

			if (heap[j] > heap[i]) { // 调整
				swap(heap[j], heap[i]);
				i = j;
				j = i * 2; //向下
			} else
				break;
		}
	}

	void upAdjust(int low, int high) {
		int i = high;
		int j = i / 2; // j为父结点

		while (j >= low) {
			if (heap[j] < heap[i]) { // 满足条件 --- 没有考虑兄弟结点
				swap(heap[j], heap[i]);
				i = j;
				j = i / 2;
			} else
				break;
		}

	}

// 建堆
	void createHeap() {
		for (int i = N / 2; i >= 1; --i)
			downAdjust(i, N);
	}

// 删除堆顶元素
	void deleteTop() {
		heap[1] = heap[N--]; // 最后一个元素覆盖， 减少堆容量
		downAdjust(1, N); // 向下调整
	}

// 插入元素
	void insertHeap(int x) {
		heap[++N] = x;
		downAdjust(1, N);
	}

}
#endif //INTERVIEW_CPP_HEAP_H
