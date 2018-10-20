//
// Created by ning on 2018/6/29.
//

#ifndef INTERVIEW_CPP_LEET80_H
#define INTERVIEW_CPP_LEET80_H

#include <iostream>
#include "../Algorithm/List.h"

using namespace std;

namespace Leetcode {
// ============================== 题目61 旋转链表
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == nullptr || k <= 0)
			return head;

		ListNode *pNext = head;
		ListNode *pMove = head;
		ListNode *test = head;

		// 统计 list length
		int length = 0;
		while (test != nullptr) {
			length += 1;
			test = test->m_pNext;
		}

		k = k % length;

		while (k > 0) {
			if (pNext == nullptr) {
				return head; // k > length of list
			}
			pNext = pNext->m_pNext;
			k--;
		}

		while (pNext->m_pNext != nullptr) {
			pMove = pMove->m_pNext;
			pNext = pNext->m_pNext;
		}

		pNext->m_pNext = head;
		head = pMove->m_pNext;
		pMove->m_pNext = nullptr;

		return head;
	}

	void test_leet61() {
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

		ListNode *result = rotateRight(&l1, 10);
		PrintList(result);
		//cout << ListLength(&l1);
	}

// ============================== 题目66 加1  [1,2,3]->[1,2,4]
	vector<int> plusOne(vector<int> &digits) {
		int carry = 1;
		vector<int> v;

		while (digits.size() > 0) {
			int x = digits.back();
			digits.pop_back();
			x = x + carry;
			v.insert(v.begin(), x % 10);
			carry = x / 10;
		}
		if (carry > 0)
			v.insert(v.begin(), carry);
		return v;
	}

// ============================== 题目70 爬楼梯(一次 1阶 或 2阶) f(1)=1 f(2)=2, n>2 f(n)=f(n-1)+f(n-2)
	int climbStairs(int n) {
		if (n <= 3)
			return n;

		int a[2] = {2, 3};
		for (int i = 4; i <= n; i++) {
			int t = a[0] + a[1];
			a[0] = a[1];
			a[1] = t;
		}
		return a[1];
	}

// 递归版本
	int climbStairs2(int n) {
		if (n <= 3)
			return n;
		return climbStairs2(n - 1) + climbStairs2(n - 2);
	}

// ============================== 题目75
	void sortColors(vector<int> &nums) {
		if (nums.size() <= 0)
			return;

		int n1 = 0;
		int n2 = 0;
		int n3 = 0; // 统计
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0)
				n1 += 1;
			else if (nums[i] == 1)
				n2 += 1;
			else
				n3 += 1;
		}

		// 修改
		for (int i = 0; i < n1; i++)
			nums[i] = 0;
		for (int i = n1; i < n1 + n2; i++)
			nums[i] = 1;
		for (int i = n1 + n2; i < n1 + n2 + n3; i++)
			nums[i] = 2;

	}

// ============================== 题目77 组合， 给定整数 n,k，返回1->n中所有可能的k个数的组合
	void getCombination(int n, int k, vector<int> &solution, vector<vector<int> > &result) {
		if (k == 0) {
			//sort to meet LeetCode requirement
			vector<int> v = solution;
			sort(v.begin(), v.end());
			result.push_back(v);
			return;
		}
		for (int i = n; i > 0; i--) {
			solution.push_back(i);
			getCombination(i - 1, k - 1, solution, result);
			solution.pop_back();
		}
	}

// 递归版本
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int> > result;
		vector<int> solution;
		getCombination(n, k, solution, result);
		return result;
	}

	void test_leet77() {
		combine(4, 2);
	}
}

#endif //INTERVIEW_CPP_LEET80_H
