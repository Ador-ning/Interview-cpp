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
#include <algorithm>
#include "../Algorithm/List.h"

using namespace std;

namespace Leetcode {
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
	// p1 -- 指向 反转范围起始结点的 父结点
	// p2 -- 指向 反转范围最后一个结点
	ListNode *Reverse(ListNode *head, ListNode *p1, ListNode *p2) {

// 链表首
		if (head == p1) {
			ListNode tmp(-1);
			tmp.m_pNext = head;
			p1 = &tmp;
			head = p2;
		}
		ListNode *p3 = p2->m_pNext; // 在p2 和 p3 之间插入结点，更新 p3
		ListNode *pMove = p1->m_pNext; // 移动结点指针

		bool Next_tag = false;

		while (pMove != p2) {
			p1->m_pNext = pMove->m_pNext;
			pMove->m_pNext = p3;
			p2->m_pNext = pMove;

			p3 = pMove; // 更新 p3
			pMove = p1->m_pNext; // 更新 pMove
		}
		return head;
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

		if (times == 0)
			return head;

		ListNode *p2 = head;
		ListNode *p1 = head;
		ListNode *NewHead = head;

		int loops = 0;
		while (times > 0) {

			for (int i = 1; i < k; ++i)
				p2 = p2; // 更新p2

			NewHead = Reverse(NewHead, p1, p2);

			// 更新 p1
			p1 = p2;
			times -= 1;
		}
		return NewHead;
	}

	void test_leet25() {
		ListNode l1(1);
		ListNode l2(2);
		ListNode l3(3);
		ListNode l4(4);
		ListNode l5(5);
		ListNode l6(6);
		ListNode l7(7);
		ListNode l8(8);
		ListNode l9(9);
		ConnectListNodes(&l1, &l2);
		ConnectListNodes(&l2, &l3);
		ConnectListNodes(&l3, &l4);
		ConnectListNodes(&l4, &l5);
		ConnectListNodes(&l5, &l6);
		ConnectListNodes(&l6, &l7);
		ConnectListNodes(&l7, &l8);
		ConnectListNodes(&l8, &l9);

		// PrintList(&l1);
		// ListNode* New = Reverse(&l1, &l1, &l6);
		// PrintList(New);
		PrintList(ReverseKGroup(&l1, 3));
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
		vector<int> n = {2, 2};
		SearchRange(n, 2);
	}

	// ============================== 题目39 数组总合 ---- 回溯法 ----

	void printMatrix(vector<vector<int> > &vv) {
		for (int i = 0; i < vv.size(); i++) {
			cout << "[";
			for (int j = 0; j < vv[i].size(); j++) {
				cout << " " << vv[i][j];
			}
			cout << "]" << endl;;
		}
	}

	void printArray(vector<int> &v) {
		cout << "{";
		for (int i = 0; i < v.size(); i++) {
			cout << " " << v[i];
		}
		cout << "}" << endl;
	}

	void CombinationSumHelper(vector<int> &candidates, int start, int target, vector<int> &solution,
	                          vector<vector<int>> &result) {
		if (target < 0)
			return;
		if (target == 0) {
			result.push_back(solution);
			return;
		}

		for (int i = start; i < candidates.size(); ++i) {
			if (i > start && candidates[i] == candidates[-1]) // skip duplicates
				continue;
			solution.push_back(candidates[i]);
			CombinationSumHelper(candidates, i, target - candidates[i], solution, result);
			solution.pop_back();
		}
	}

	vector<vector<int>> CombinationSum(vector<int> &candidates, int target) {
		vector<vector<int>> result;

		if (candidates.size() <= 0)
			return result;

		sort(candidates.begin(), candidates.end());

		vector<int> solution;
		CombinationSumHelper(candidates, 0, target, solution, result);

		return result;
	}

	void test_leet39() {
		int a[] = {4, 2, 3, 3, 5, 7};
		vector<int> v(a, a + sizeof(a) / sizeof(int));
		int target = 7;
		cout << "array  = ";
		printArray(v);
		cout << "target = " << target << endl;

		vector<vector<int> > vv = CombinationSum(v, target);
		printMatrix(vv);

		return;
	}


	// ============================== 题目46 全排列  -- 递归
	// STL 算法库
	vector<vector<int>> permute(vector<int> &num) {
		vector<vector<int>> result;
		sort(num.begin(), num.end());
		do {
			result.push_back(num);
		} while (next_permutation(num.begin(), num.end()));
		return result;
	}

	// 递归 方式
	void swap(vector<int> &o, int i, int j) {
		if (o.size() <= 1 || i > (o.size() - 1) || j > (o.size() - 1))
			return;
		int temp = o[i];
		o[i] = o[j];
		o[j] = temp;
	}

	void PrintVector(vector<int> v) {
		if (v.size() <= 0)
			return;

		vector<int>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
			cout << *it << '\t';
		cout << endl;
		return;
	}

	bool isSwap(vector<int> n, int index) {
		for (int i = index + 1; i < n.size(); i++)
			if (n[index] == n[i])
				return false;
		return true;
	}

	int sum = 0;

	void permute_recursive(vector<int> &num, int index) {
		if (index == num.size() - 1) {  // 全排列结束
			sum++;
			PrintVector(num);
		} else {
			for (int i = index; i < num.size(); i++) {
				if (isSwap(num, i)) {   // 判断 相同数字
					swap(num, index, i);   // 交换
					permute_recursive(num, index + 1); // 递归剩余
					swap(num, index, i); // 交换回来
				}
			}
		}
		return;
	}

	// 非递归方式
	void nextPermutation(vector<int> &nums) {
		if (nums.size() <= 1)
			return;

		for (int i = nums.size() - 1; i >= 0; i++) {
			if (nums[i - 1] < nums[i]) {    // find first nums[i-1] < nums[i],  [n-1 -> 0]
				int j = nums.size() - 1;
				while (nums[i - 1] >= nums[j])    // find first nums[i-1] < nums[j], j  [n-1 -> i]
					j--; // pass

				// swap
				int tmp = nums[i - 1];
				nums[i - 1] = nums[j];
				nums[j] = tmp;

				// reverse i -> n-1
				reverse(nums.begin() + i, nums.end());
				return;
			}


			if (i == 1) {   // 4 3 2 1
				reverse(nums.begin(), nums.end());
				return;
			}
		}
	}


	void test46() {
		vector<int> n = {1, 2, 3};
		nextPermutation(n);
	}
}
#endif //INTERVIEW_CPP_40_H
