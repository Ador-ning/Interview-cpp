//
// Created by ning on 2018/6/22.
//

#ifndef INTERVIEW_CPP_40_H
#define INTERVIEW_CPP_40_H

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include "../Algorithm/List.h"

using namespace std;

// ==============================   题目20  有序链表合并--递归实现 // -- 写循环
ListNode *MergeTwoList(ListNode *l1, ListNode *l2) {

	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1; // base situation + 剩余情况

	ListNode *pMerge = nullptr;

	// 递归
	if (l1->m_nKey < l2->m_nKey) {
		pMerge = l1;
		pMerge->m_pNext = MergeTwoList(l1->m_pNext, l2);
	} else {
		pMerge = l2;
		pMerge->m_pNext = MergeTwoList(l2->m_pNext, l1);
	}
	return pMerge;
}

void test_leet21() {
	ListNode l1(1);
	ListNode l2(4);
	ListNode l3(5);
	ConnectListNodes(&l1, &l2);
	ConnectListNodes(&l2, &l3);

	ListNode a1(1);
	ListNode a2(3);
	ListNode a3(4);
	ConnectListNodes(&a1, &a2);
	ConnectListNodes(&a2, &a3);
	// PrintList(&l1);
	// PrintList(&a1);

	ListNode *h = MergeTwoList(&a1, &l1);
	PrintList(h);
}

// ==============================   题目26 删除有序数组中重复的元素 -- 原地
int RemoveDuplications(vector<int> &nums) {

	int n = nums.size();
	if (n <= 0)
		return 0;

	// 1. 删除重复
	// 2. 移动数据 -- 覆盖即可

	bool Dup = false; // 重复标志

	int MoveLength = 0; // 向左覆盖，长度

	for (int i = 0; i < n; ++i) {

		int DupK = 0; // 单个重复次数
		if (nums[i] == nums[i + 1]) { // 遇到重复
			DupK++;
			while (nums[i] == nums[i + 1 + DupK] && (i + 1 + DupK) < n) // 越界
				DupK++; // 继续查重

			// 覆盖
			for (int j = i + 1; j < n; ++j)
				nums[j] = nums[j + DupK];
			cout << "one dup:" << DupK << endl;
		}

		n -= DupK; // 该覆盖后
		MoveLength += DupK;
	}
	// cout << "all dup numbers:" << MoveLength << endl;

	vector<int>::iterator it = nums.begin();
	nums.erase(it + nums.size() - MoveLength, it + nums.size());
	return n;
}

void test_leet26() {
	vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0};// {0, 0, 1, 1, 1, 1, 2, 2, 2, 4};// ; // {0,0,1,1,1,2,2,3,3,4}
	cout << RemoveDuplications(nums) << endl;
}

// ============================== 题目28 判断str2是否为str1的子串
int strStr(const string s1, const string s2) {

	if (s1 == "")
		return -1;
	if (s2 == " " || s2 == "")
		return 0; // base satuation

	int len = s2.size();

	for (int i = 0; i < s1.size(); ++i) {
		if (s1.substr(i, len) == s2)
			return i; // 返回第一个 index
	}
	return -1; // 不存在
}

void test_leet28() {
	const string haystack = "";
	const string needle = "";
	cout << strStr(haystack, needle);
}

#endif //INTERVIEW_CPP_40_H
