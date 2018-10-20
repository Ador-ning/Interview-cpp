//
// Created by ning on 2018/5/29.
//

#ifndef INTERVIEW_CPP_SORTEDARRAY_H
#define INTERVIEW_CPP_SORTEDARRAY_H

#include <iostream>

using namespace std;

namespace Algorithm {

// 在排序数组中， 利用已排序特性，进行问题解决

/*
 * 面试53： 统计一个数字在排序数组中出现的次数
 */
// 找到数组中第一K的下标，如果K不存在，返回-1
	int GetFirstK(const int *data, int length, int k, int start, int ed) {

		if (start > ed)
			return -1;

		int middleIndex = (start + ed) / 2;
		int middleData = data[middleIndex];

		if (middleData == k) {//K出现的范围， 在数组中间， 向左缩小范围
			if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)
				return middleIndex;
			else
				ed = middleIndex - 1;

		} else if (middleData > k) //K出现的范围， 不在数组中间
		{
			ed = middleIndex - 1;
		} else {
			start = middleIndex + 1;
		}

		return GetFirstK(data, length, k, start, ed);
	}

// 找到数组中最后一个k的下标。如果数组中不存在k，返回-1
	int GetLastK(const int *data, int length, int k, int start, int ed) {
		if (start > ed)
			return -1;

		int middleIndex = (start + ed) / 2;
		int middleData = data[middleIndex];

		if (middleData == k) {
			if ((middleIndex < length - 1 && data[middleIndex + 1] != k)
			    || middleIndex == length - 1)
				return middleIndex;
			else
				start = middleIndex + 1;
		} else if (middleData < k)
			start = middleIndex + 1;
		else
			ed = middleIndex - 1;

		return GetLastK(data, length, k, start, ed);
	}


	int GetNumberOfK(const int *data, int length, int k) {
		int number = 0;

		if (data != nullptr && length > 0) {
			int first = GetFirstK(data, length, k, 0, length - 1);
			int last = GetLastK(data, length, k, 0, length - 1);

			if (first > -1 && last > -1)
				number = last - first + 1;
		}
		return number;
	}

	void Test(const char *testName, int data[], int length, int k, int expected) {
		if (testName != nullptr)
			printf("%s begins: ", testName);

		int result = GetNumberOfK(data, length, k);
		if (result == expected)
			printf("Passed.\n");
		else
			printf("Failed.\n");
	}

	void ArrayTest1() {
		int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
		Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
	}

// 变形题1
/*
 * 一个长度为n-1的递增排序数组中的数字都是唯一的，并且每个数字都在0 -> n-1范围内
 *  0 -> n-1仅有一个数字不再该数组中
 */
	int GetMissingNumber(const int *numbers, int length) {
		if (numbers == nullptr || length <= 0)
			return -1;

		int left = 0;
		int right = length - 1;

		while (left <= right) {
			int middle = (right + left) >> 1;

			if (numbers[middle] != middle) {
				if (middle == 0 || numbers[middle - 1] == middle - 1)
					return middle;
				right = middle - 1;
			} else
				left = middle + 1;
		}

		if (left == length)
			return length;

		return -1; // 无效
	}

// 变形题2
/*
 * 假设一个单调递增的数组里的每一个元素都是整数并且是唯一的
 * 目标： 找出数组中任意一个数值等于其下标的元素
 */
	int GetNumberSameAsIndex(const int *numbers, int length) {
		if (numbers == nullptr || length <= 0)
			return -1;

		int left = 0;
		int right = length - 1;
		while (left < right) {
			int middle = left + ((right - left) >> 1);

			if (numbers[middle] == middle)
				return middle;

			if (numbers[middle] > middle)
				right = middle - 1; // 在左侧
			else
				left = middle + 1; // 在右侧
		}
		return -1;
	}

// ######################### next
// 和为s的两个数字 -- 有序
/*
 * 面试57：输入一个递增数组和一个数字s，在数组中查找两个数，使得和为s
 * 如果有多对数字，输出任意一对即可
 */
	bool FindNumbersWithSum(int *data, int length, int sum, int *num1, int *num2) {
		bool found = false;

		if (length < 1 || num1 == nullptr || num2 == nullptr)
			return found;

		int ahead = length - 1;
		int behind = 0;

		while (ahead > behind) {
			long long curSum = data[ahead] + data[behind];

			if (curSum == sum) {
				*num1 = data[ahead];
				*num2 = data[behind];
				found = true;
				break;
			} else if (curSum > sum)
				ahead--; // 调整1
			else
				behind++; // 调整2
		}

		return found;
	}

}
#endif //INTERVIEW_CPP_SORTEDARRAY_H
