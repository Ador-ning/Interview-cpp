//
// Created by ning on 2018/4/30.
//

#ifndef PROJECT_MYSTRINGS_H
#define PROJECT_MYSTRINGS_H

#include <iostream>
#include <stdio.h>
#include <cassert>
#include <cstring>

using namespace std;

// 将 整数 转换为 string
/*
 * 改函数
 * */
void int2str(int n, char *str) {
	char buf[10] = " ";
	int i = 0;
	int len = 0;

	int temp = n < 0 ? -n : n; // 将 n < 0 转 为正整数

	if (str == NULL) {
		cout << " No memory to storage string !" << endl;
		return;
	}

	while (temp) {
		buf[i++] = (temp % 10) + '0';
		temp = temp / 10;
	}

	len = n < 0 ? ++i : i; // 如果 n 为负数，则多需要一位来存储 负号
	str[i] = 0;

	while (1) {
		i--;

		if (buf[len - i - 1] == 0) // 循环停止标志
			break;

		str[i] = buf[len - i - 1]; // 将 字符 复制到 字符串中

		if (i == 0) // 如果是负数 首处加 '-'
			str[i] = '-';
	}
}

int str2int(const char *str) {
	int temp = 0;
	const char *ptr = str; // ptr保存str字符串开头

	if (*str == '-' || *str == '+') // 跳过 正负号
		str++;

	while (*str != '\0') { // 循环至字符串结束

		if ((*str < '0') || (*str > 9)) {
			cout << "str have some no int char !" << endl;
			break;
		}

		temp = temp * 10 + (*str - '0');
		str++;
	}

	if (*ptr == '-')
		temp = -temp;

	return temp;
}

char *my_strcpy(char *strDest, const char *strSrc) {

	if ((strDest == NULL) || (strSrc == NULL)) // 判断参数是否有效
		return NULL;

	char *strDestCopy = strDest; // 保存目标字符串首地址
	while ((*strDest++ = *strSrc) != '\0'); // 复制

	return strDestCopy;
}

void *memcpy2(void *memTo, void *memFrom, int size) {
	if ((memTo == nullptr) || (memFrom == nullptr))
		return nullptr;

	char *tempFrom = memFrom;
	char *tempTo = memTo; // 指针变量多余

	while (size-- > 0)
		*tempTo++ = *tempFrom++;
	return memTo;
}

int getStrLen(const char *strSrc) {
	int len = 0; // 保存长度

	while (*strSrc++ != '\0')
		len++;

	return len;
}

// 时间复杂度 O(n^2)
const char *find_subStr(const char *src, const char *sub) {
	const char *bp;
	const char *sp;

	if (src == nullptr || sub == nullptr)
		return nullptr; // 失败

	while (*src) {
		bp = src;
		sp = sub;
		do {
			if (*sp == '\0') // 子串结束位置
				return src;
		} while (*bp++ == *sp++);
		src += 1;
	}
	return nullptr; // 失败
}

// 将字符串各 单词顺序 翻转
// 方法：单词逆置一次， 然后整体逆置一次
void RevStr1(char *src) {
	char *start = src;
	char *end = src;
	char *ptr = src;

	while (*ptr++ != '\0') { // 遍历字符串
		if (*ptr == ' ' || *ptr == '\0') { // 找到一个单词, ptr指向 空格或字符串结束处
			end = ptr - 1; // end指向单词末尾
			while (start < end)
				swap(*start++, *end++); // 将单词的字母逆置
			start = end = ptr + 1; // 指向下一个单词
		}
	}
	start = src, end = ptr - 2; // start指向字符串开头， end指向字符串结尾
	while (start < end)
		swap(*start++, *end++); // 逆置整个字符串
}

// 方法：先整体逆置，然后进行单词逆置
void RevStr2(char *src) {
	// 省
}

void RevStr2(char *src) {}

// 判断回文数
int isRevStr(const char *str) {
	int i, len;
	int tag = 1; // 1表示是回文数 0表示不是

	if (str == nullptr)
		return -1;
	len = strlen(str); // #########

	for (i = 0; i < len / 2; i++) {
		if (*(str + i) != *(str + len - i - 1)) {
			tag = 0;
			break;
		}
	}
	return tag;
}



#endif //PROJECT_MYSTRINGS_H
