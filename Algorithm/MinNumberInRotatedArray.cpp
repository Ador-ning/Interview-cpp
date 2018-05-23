#include <cstdio>
#include <exception>
#include <stdexcept>

/*
面试：
	把数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转
	输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素
*/
// 查找 坐标范围内，数组最小值
int MinInOrder(const int numbers[], int index1, int index2) {
	int result = numbers[index1];
	if (index1 < index2) {
		for (int i = index1 + 1; i < index2; ++i) {
			if (result > numbers[i])
				result = numbers[i];
		}
		return result;
	}
}

//
int Min(int numbers[], int length) {
	if (numbers == NULL || length <= 0) {
		std::logic_error ex("Invalid parameters.\n");
		throw std::exception(ex);
	}

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;

	while (numbers[index1] >= numbers[index2]) {
		// 如果 index1 和 index2 指向相邻的两个数 ，
		// 则 index1 指向第一递增子数组的最后一个数字，
		// index2指向第二个子数组的第一个数字，也就是数组中的最小数字
		if (index2 - index1 == 1) {
			indexMid = index2;
			break;
		}

		// 如果下标为 index1、index2和indexMid指向的三个数字相等
		// 只能顺序查找
		int indexMid = (index2 + index1) / 2;
		if (numbers[index1] == numbers[2] && numbers[indexMid] == numbers[index1])
			return MinInOrder(numbers, index1, index2);

		// 缩小查找范围   -> 跳过有序部分
		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}

	return numbers[indexMid];
}


// ====================测试代码====================
void Test(int *numbers, int length, int expected) {
	int result = 0;
	try {
		result = Min(numbers, length);

		for (int i = 0; i < length; ++i)
			printf("%d ", numbers[i]);

		if (result == expected)
			printf("\tpassed\n");
		else
			printf("\tfailed\n");
	}
	catch (...) {
		if (numbers == NULL)
			printf("Test passed.\n");
		else
			printf("Test failed.\n");
	}
}

int main(int argc, char *argv[]) {
	// 典型输入，单调升序的数组的一个旋转
	int array1[] = {3, 4, 5, 1, 2};
	Test(array1, sizeof(array1) / sizeof(int), 1);

	// 有重复数字，并且重复的数字刚好的最小的数字
	int array2[] = {3, 4, 5, 1, 1, 2};
	Test(array2, sizeof(array2) / sizeof(int), 1);

	// 有重复数字，但重复的数字不是第一个数字和最后一个数字
	int array3[] = {3, 4, 5, 1, 2, 2};
	Test(array3, sizeof(array3) / sizeof(int), 1);

	// 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
	int array4[] = {1, 0, 1, 1, 1};
	Test(array4, sizeof(array4) / sizeof(int), 0);

	// 单调升序数组，旋转0个元素，也就是单调升序数组本身
	int array5[] = {1, 2, 3, 4, 5};
	Test(array5, sizeof(array5) / sizeof(int), 1);

	// 数组中只有一个数字
	int array6[] = {2};
	Test(array6, sizeof(array6) / sizeof(int), 2);

	// 输入nullptr
	Test(NULL, 0, 0);

	return 0;
}
