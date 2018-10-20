#include <cstdio>
#include <cstdlib>

/*
面试：
长度为 n+1 数组中所有数字范围为 1->n，数组中至少有一个数字是重复的
找出数组中重复的数字，但是不能修改输入的数组
*/
int countRange(const int *numbers, int length, int start, int end) {
	if (numbers == NULL)
		return 0;

	int count = 0;

	for (int i = 0; i < length; ++i) {
		if (numbers[i] > start && numbers[i] <= end)
			++count;
	}
	return count;
}

int getDuplication(const int *numbers, int length) {
	/*
	参数1：
	参数2：
	*/
	if (numbers == NULL || length <= 0)
		return -1;

	int start = 1;
	int end = length - 1;

	while (end >= start) {
		int middle = ((end - start) >> 1) + start;

		// 统计 数组中 数值在 start->middle 范围的个数
		int count = countRange(numbers, length, start, middle);

		// 终止情况
		if (end == start) {
			if (count > 1)
				return start;
			else
				break;
		}

		if (count > (middle - start + 1))
			end = middle; // 如果 数组中在 范围内数字的个数 大于 该子部分长度，证明  该部分一定包含有重复的数字
		else
			start = middle + 1;
	}
	return -1;
}

int main() {
	return 0;
}
