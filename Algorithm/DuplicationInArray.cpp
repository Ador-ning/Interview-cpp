#include <cstdio>
#include <cstdlib>

/*
面试： 找出数组中重复的数字
题目：长度为n的数组中，所有数字都在0->n-1的范围内
*/


bool duplicate(int numbers[], int length, int *duplication) {
	/*
	参数1：
	参数2：
	参数3：
	*/
	if (numbers == NULL || length == 0)
		return false;

	for (int i = 0; i < length; ++i) {
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	for (int i = 0; i < length; ++i) {
		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				return true;
			}

			// 交换 numbers[i] 和 numbers[numbers[i]]
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}

	return false;
}


// ******** 测试代码
bool contains(int array[], int length, int number) {
	for (int i = 0; i < length; ++i) {
		if (array[i] == number)
			return true;
	}

	return false;
}


void
test(const char *testName, int numbers[], int lengthNumbers, int exceptedArray[], int excepted, bool validArgument) {
	printf("%s begins: ", testName);

	int duplication;
	bool validInput = duplicate(numbers, lengthNumbers, &duplication);

	if (validArgument == validInput) {
		if (validArgument) {
			if (contains(exceptedArray, excepted, duplication))
				printf("Passed.\n");
			else
				printf("Failed.\n");
		} else
			printf("Passed.\n");
	} else
		printf("Failed.\n");
}


// 重复的数字是数组中最小的数字
void test1() {
	int numbers[] = {2, 1, 3, 1, 4};
	int duplications[] = {1};
	test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2() {
	int numbers[] = {2, 4, 3, 1, 4};
	int duplications[] = {4};
	test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3() {
	int numbers[] = {2, 4, 2, 1, 4};
	int duplications[] = {2, 4};
	test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4() {
	int numbers[] = {2, 1, 3, 0, 4};
	int duplications[] = {-1}; // not in use in the test function
	test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5() {
	int numbers[] = {2, 1, 3, 5, 4};
	int duplications[] = {-1}; // not in use in the test function
	test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6() {
	int *numbers = NULL;
	int duplications[] = {-1}; // not in use in the test function
	test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}


int main() {
	test6();
	return 0;
}