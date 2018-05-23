#include <cstdio>

/*
斐波那契数列：
*/

// 方法1： 递归
long long Fibonacci1(unsigned int n) {
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}

// 方法2： 循环
long long Fibonacci2(unsigned int n) {
	int result[2] = {0, 1};

	if (n < 2 && n > 0)
		return result[n];

	long long fibOne = 1;
	long long fibTwo = 0;
	long long fibN = 0;

	for (unsigned int i = 2; i <= n; ++i) {
		fibN = fibOne + fibTwo;
		fibTwo = fibOne;
		fibOne = fibN;
	}

	return fibN;
}


// ====================测试代码====================
void Test(int n, int expected) {
	if (Fibonacci1(n) == expected)
		printf("Test for %d in solution1 passed.\n", n);
	else
		printf("Test for %d in solution1 failed.\n", n);

	if (Fibonacci2(n) == expected)
		printf("Test for %d in solution2 passed.\n", n);
	else
		printf("Test for %d in solution2 failed.\n", n);
}


int main() {
	Test(0, 0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(6, 8);
	Test(7, 13);
	Test(8, 21);
	Test(9, 34);
	Test(10, 55);

	Test(40, 102334155);

	return 0;
}