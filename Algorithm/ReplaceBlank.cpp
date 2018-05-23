#include <cstdio>
#include <cstdlib>
#include <cstring>

/*
面试： 字符串中空格替换
把字符串中每个空格替换成 "%20"
*/

/*
替换的基本思路： O(n)时间复杂度
1. 统计 需要替换的 数目 -> O(n)
2. 双指针， 自后向前一次替换，移动  -> O(n)
*/

// length 为字符数组实际容量，大于或等于字符串的实际长度
void ReplaceBlank(char str[], int length) {

	if (str == NULL || length <= 0)
		return;

	// RealLength 为字符串的实际长度
	int RealLength = 0;
	int NumberBlank = 0;

	int i = 0;

	while (str[i] != '\0') {
		++RealLength;

		if (str[i] == ' ')
			++NumberBlank;
		++i;
	} // 统计出 字符串的长度 和  空格数目

	int newlength = RealLength + NumberBlank * 2;

	if (newlength > length)
		return; // 应该重新分配内存

	// 替换
	int IndexOriginal = RealLength;
	int IndexNew = newlength;
	while (IndexOriginal >= 0 && IndexNew > IndexOriginal) {
		if (str[IndexOriginal] == ' ') {
			str[IndexNew--] = '0';
			str[IndexNew--] = '2';
			str[IndexNew--] = '%';
		} else
			str[IndexNew--] = str[IndexOriginal];
		--IndexOriginal;
	}
}


// ====================测试代码====================
void Test(const char *testName, char str[], int length, char expected[]) {
	if (testName != NULL)
		printf("%s begins: ", testName);

	ReplaceBlank(str, length);

	if (expected == NULL && str == NULL)
		printf("passed.\n");
	else if (expected == NULL && str != NULL)
		printf("failed.\n");
	else if (strcmp(str, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}

// 空格在句子中间
void Test1() {
	const int length = 100;

	char str[length] = "hello world!";
	Test("Test1", str, length, "hello%20world!");
}

int main() {
	Test1();
	return 0;
}