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

// ============================== 题目24 单链表 相邻两结点两两交换
ListNode *SwapPairs(ListNode *head) {
	if (head == nullptr)
		return nullptr;
	if (head->m_pNext == nullptr)
		return head;    // 一个结点

	ListNode *next = head->m_pNext;
	head->m_pNext = next->m_pNext;
	next->m_pNext = head;
	head = next; // 调整前两个结点
	if (head->m_pNext->m_pNext == nullptr)
		return head; // 两个结点

	ListNode *pre = head->m_pNext;
	ListNode *p = pre->m_pNext;
	if (p->m_pNext == nullptr)
		return head; // 三个结点
	next = p->m_pNext;

	for (; next != nullptr; next = next->m_pNext->m_pNext) {
		p->m_pNext = next->m_pNext;
		next->m_pNext = p;
		pre->m_pNext = next; // 调整

		p = next;
		next = p->m_pNext; // 换位置

		if (next->m_pNext == nullptr)
			return head; // 偶数结点

		pre = pre->m_pNext->m_pNext;
		p = p->m_pNext->m_pNext; // 循环更新
		if (p->m_pNext == nullptr)
			return head; // 奇数结点
	}

}

void test_leet24() {
	ListNode l1(1);
	ListNode l2(2);
	// ListNode l3(3);
	// ListNode l4(4);
	// ListNode l5(5);
	// ListNode l6(6);
	// ListNode l7(7);
	// ListNode l8(8);
	// ListNode l9(9);
	ConnectListNodes(&l1, &l2);
	// ConnectListNodes(&l2, &l3);
	// ConnectListNodes(&l3, &l4);
	// ConnectListNodes(&l4, &l5);
	// ConnectListNodes(&l5, &l6);
	// ConnectListNodes(&l6, &l7);
	// ConnectListNodes(&l7, &l8);
	// ConnectListNodes(&l8, &l9);
	PrintList(SwapPairs(&l1));

	// PrintList(&l1);
}

// ============================== 题目25 k个一组反转链表

ListNode *Reverse(ListNode *p, int k) {
	// 反转一组， p -> 反转起始结点
}

ListNode *ReverseKGroup(ListNode *head, int k) {

	if (head == nullptr || k <= 1)
		return head; // base situations

	ListNode *p = head;
	int num = 0;
	while (p != nullptr) {
		num += 1;
		p = p->m_pNext;
	} // 结点数目

	int times = num / k; // 需要反转的次数

	cout << num << '\t' << times << endl;
	return head;
}

void test_leet25() {
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	ListNode l4(4);
	// ListNode l5(5);
	// ListNode l6(6);
	// ListNode l7(7);
	// ListNode l8(8);
	// ListNode l9(9);
	ConnectListNodes(&l1, &l2);
	ConnectListNodes(&l2, &l3);
	ConnectListNodes(&l3, &l4);
	// ConnectListNodes(&l4, &l5);
	// ConnectListNodes(&l5, &l6);
	// ConnectListNodes(&l6, &l7);
	// ConnectListNodes(&l7, &l8);
	// ConnectListNodes(&l8, &l9);
	ReverseKGroup(&l1, 3);
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

// ============================== 题目27
int RemoveElement(vector<int> &nums, int val) {
	int n = nums.size();
	if (n <= 0)
		return 0; // base

	int ValNumLeft = 0; // 值为val的数量
	int ValNumRight = 0;
	int BackIndex = 1; // 换值调整 index

	for (int i = 0; i <= n - BackIndex; ++i) {  // i <= n-BackIndex
		if (nums[i] == val) {
			ValNumLeft += 1;

			// 向左找到
			while ((n - BackIndex) > i) {
				if (val == nums[n - BackIndex]) { // 值 == val
					BackIndex += 1;
					ValNumRight += 1;
				} else {
					nums[i] = nums[n - BackIndex]; // 值 != val
					BackIndex += 1;
					break;
				}
			}
		}
	}

	vector<int>::iterator it = nums.begin();
	for (; it < nums.end(); ++it)
		cout << *it << '\t';
	cout << endl;

	return (n - ValNumLeft - ValNumRight);
}

void test_leet27() {
	vector<int> n = {0, 1, 2, 2, 3, 0, 4, 2, 10};// {1};
	cout << RemoveElement(n, 10);
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

// ============================== 题目29 两整数数相除
#define  INT_MAX 2147483647
#define INT_MIN (-INT_MAX-1)

int divide(int dividend, int divisor) {
	int sign = (float) dividend / divisor > 0 ? 1 : -1; // 符号
	unsigned int dvd = dividend > 0 ? dividend : -dividend; // 变正数
	unsigned int dvs = divisor > 0 ? divisor : -divisor;

	unsigned int bit_num[32]; // 存放 -- 除数的 i倍结果
	unsigned int i = 0;
	long long d = dvs;
	bit_num[i] = d; // 除数

	while (d <= dvd)
		bit_num[++i] = d = d << 1; // 存放

	i--;
	unsigned int result = 0;

	while (dvd >= dvs) { // 被除数 >= 除数
		if (dvd >= bit_num[i]) {
			dvd -= bit_num[i]; // 余数
			result += (1 << i); // 结果
		} else {
			i--;
		}
	}

	if (result > INT_MAX && sign > 0)
		return INT_MAX;
	return (int) result * sign;
}

void test_leet29() {
	cout << '\t' << divide(7, -3) << endl;
}

// ============================== 题目33 Search in Rotated Sorted Array -- [4,5,6,7,0,1,2]
int search(vector<int> &nums, int target) {
	int n = nums.size();

	if (n <= 0)
		return -1; // base situation
	if (n == 1)
		return nums[0] == target ? 0 : -1;

	int low = 0, high = n - 1;

	while (low <= high) {

		if (nums[low] < nums[high] && (target < nums[low] || target > nums[high]))
			return -1;

		// remove the duplication
		while (low < high && nums[low] == nums[high])
			low++;

		int mid = low + (high - low) / 2;

		if (nums[low] == target)
			return low;
		if (nums[high] == target)
			return high;
		if (nums[mid] == target)
			return mid;  // 返回

		// the target in non-rotated array  情况1 target在左侧有序部分
		if (nums[low] < nums[mid] && target >= nums[low] && target < nums[mid]) {
			high = mid - 1;
			continue;
		}

		// the target in non-rotated array  情况2 target在右侧有序部分
		if (nums[mid] < nums[high] && target >= nums[mid] && target < nums[high]) {
			low = mid + 1;
			continue;
		}

		// the target in rotated array  情况3  旋转点在左侧
		if (nums[low] > nums[mid]) {
			high = mid - 1;
			continue;
		}
		// the target in rotated array  情况4 旋转点在右侧
		if (nums[mid] > nums[high]) {
			low = mid + 1;
			continue;
		}
		low++;
	}
	return -1;
}

void test_leet33() {
	vector<int> nums1 = {5, 1, 3};
	cout << search(nums1, 3) << endl;
}

// ============================== 题目34 升序数组中，查找value，返回index

// 返回 val index
int FindVal(vector<int> &nums, int val, int n) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (nums[mid] > val)
			right = mid - 1;
		else if (nums[mid] < val)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

vector<int> SearchRange(vector<int> &nums, int target) {
	int n = nums.size();
	vector<int> result;
	int index_left = 0;
	int index_right = 0;

	if (n <= 0) {
		index_left = -1;
		index_right = -1;
	}

	int index = FindVal(nums, target, n);

	if (index == -1) { // 不存在
		index_left = -1;
		index_right = -1;
	}

	if (index > -1) { // 找左右两侧索引
		for (int i = index + 1; i < n; ++i) { // 右侧
			if (nums[i] == target)
				if (i == n - 1) {
					index_right = i;
					break;
				} else
					continue;
			index_right = i - 1;
			break;
		}
		for (int i = index; i >= 0; --i) { // 左侧
			if (nums[i] == target)
				continue;
			index_left = i + 1;
			break;
		}
	}

	cout << index << endl;
	cout << index_left << '\t' << index_right << endl;

	result.push_back(index_left);
	result.push_back(index_right);
	return result;
}

void test_leet34() {
	vector<int> n = { 2, 2};
	SearchRange(n, 2);
}

#endif //INTERVIEW_CPP_40_H
