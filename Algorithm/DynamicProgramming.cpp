#include <iostream>
#include <cmath>

/*
面试题： 剪绳子
题目： 一根长度为 n 的绳子，剪成 m 段 （ m n 都是整数，n>1 和 m>=1）
每段绳子的长度记为 k[0] k[1] ... k[m]. 求 k[0]*k[1]*k[2]...k[m]的最大值
*/


// 动态规划解题
int solution1(int length) {
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int *products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;

	for (int i = 4; i <= length; ++i) {
		max = 0;
		for (int j = 1; j <= i / 2; ++j) {
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;
			products[i] = max;
		}
	}

	max = products[length];

	delete[] products;
	return max;
}

// 贪心算法解题
int solution2(int length) {
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	// 尽可能多地减去长度为 3 的绳子
	int timesof3 = length / 3;

	// 当绳子最后剩下的长度为 4 时候，不能剪去长度为 3 的绳子段
	if (length - timesof3 * 3 == 1)
		timesof3 -= 1;

	int timesof2 = (length - timesof3 * 3) / 2;

	return (int) (pow(3, timesof3)) * (int) (pow(2, timesof2));
}


// ----------------- 测试代码
void test(const char *testname, int length, int excepted) {
	int results1 = solution1(length);
	if (results1 == excepted)
		std::cout << "Solution1 for" << testname << " passed." << std::endl;
	else
		std::cout << "Solution1 for" << testname << " failed." << std::endl;

	int results2 = solution2(length);
	if (results2 == excepted)
		std::cout << "Solution2 for" << testname << " passed." << std::endl;
	else
		std::cout << "Solution2 for" << testname << " failed." << std::endl;

}

void test1() {
	int length = 1;
	int expected = 0;
	test("test1", length, expected);
}

void test2() {
	int length = 2;
	int expected = 1;
	test("test2", length, expected);
}

void test3() {
	int length = 3;
	int expected = 2;
	test("test3", length, expected);
}

void test4() {
	int length = 4;
	int expected = 4;
	test("test4", length, expected);
}

void test5() {
	int length = 5;
	int expected = 6;
	test("test5", length, expected);
}

void test6() {
	int length = 6;
	int expected = 9;
	test("test6", length, expected);
}

void test7() {
	int length = 7;
	int expected = 12;
	test("test7", length, expected);
}

void test8() {
	int length = 8;
	int expected = 18;
	test("test8", length, expected);
}

void test9() {
	int length = 9;
	int expected = 27;
	test("test9", length, expected);
}

void test10() {
	int length = 10;
	int expected = 36;
	test("test10", length, expected);
}

void test11() {
	int length = 50;
	int expected = 86093442;
	test("test11", length, expected);
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();

	return 0;
}
