//
// Created by ning on 2018/6/29.
//

#ifndef INTERVIEW_CPP_LEET100_H
#define INTERVIEW_CPP_LEET100_H

#include <iostream>
#include "../Algorithm/List.h"

using namespace std;
namespace Leetcode {
// ============================== 题目83 删除链表中重复元素
	ListNode *deleteDuplicates(ListNode *head) {

		if (head == nullptr)
			return head;
		ListNode *p = head;
		ListNode *pDelete = head->m_pNext;

		while (pDelete->m_pNext != nullptr) {
			if (p->m_nKey == pDelete->m_nKey) {
				p->m_pNext = pDelete->m_pNext;
			} else {
				p = p->m_pNext;
			}
			pDelete = pDelete->m_pNext;
		}
		return head;
	}

// ============================== 题目86 分割链表
	ListNode *partition(ListNode *head, int x) {
		if (head == nullptr)
			return head;

		ListNode *pInsert;
		bool ChangeHead = 0;
		bool tag = 0;
		int time = 1;

		if (head->m_nKey < x) {
			pInsert = head;
		} else {
			ListNode tmp(0); // 临时结点
			tmp.m_pNext = head;

			pInsert = &tmp;
			ChangeHead = 1;
			tag = 1;
		}

		ListNode *pMove = head->m_pNext;
		ListNode *pPre = head;

		while (pMove != nullptr) {
			if (pMove->m_nKey < x && tag) {
				pPre->m_pNext = pMove->m_pNext; // 1. 链接后面
				pMove->m_pNext = pInsert->m_pNext; // 2. 插入第一步
				pInsert->m_pNext = pMove; // 3. 插入第二步

				// head = pMove;
				if (ChangeHead == 1 && time == 1) {
					head = pMove;
					time -= 1;
				}

				pMove = pPre->m_pNext;
				pInsert = pInsert->m_pNext;
			} else {
				if (pMove->m_nKey >= x)
					tag = 1;
				pMove = pMove->m_pNext;
				pPre = pPre->m_pNext;
			}
		}
		return head;
	}

	void test_leet86() {
		ListNode l1(6);
		ListNode l2(4);
		ListNode l3(3);
		ListNode l4(2);
		ListNode l5(5);
		ListNode l6(2);
		ConnectListNodes(&l1, &l2);
		ConnectListNodes(&l2, &l3);
		ConnectListNodes(&l3, &l4);
		ConnectListNodes(&l4, &l5);
		ConnectListNodes(&l5, &l6);

		PrintList(partition(&l1, 3));
	}

// ============================== 题目92 反转链表2 反转 m->n结点
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (m >= n || head == nullptr)
			return head; // base

		ListNode *pre;
		ListNode *next = head;
		bool ChangeHead = false;

		// pre 指定 m上一个结点， next 指向n结点
		if (m == 1) {
			ListNode t(0);
			pre = &t;
			t.m_pNext = head;
			ChangeHead = true;
		} else {
			pre = head;
			m -= 1;
		}
		// 指针移动到指定位置
		while (next->m_pNext != nullptr) {
			if (m > 1) {
				pre = pre->m_pNext;
				m -= 1;
			}
			if (n > 1) {
				n -= 1;
				next = next->m_pNext;
			} else
				break;
		}

		if (ChangeHead == true)
			head = next; //

		ListNode *pMove = pre->m_pNext;
		while (pMove != next) {
			pre->m_pNext = pMove->m_pNext;
			pMove->m_pNext = next->m_pNext;
			next->m_pNext = pMove;
			pMove = pre->m_pNext;
		}
		return head;
	}

	void test_leet92() {
		ListNode l1(3);
		ListNode l2(5);
		//ListNode l3(3);
		//ListNode l4(4);
		//ListNode l5(5);

		ConnectListNodes(&l1, &l2);
		//ConnectListNodes(&l2, &l3);
		//ConnectListNodes(&l3, &l4);
		//ConnectListNodes(&l4, &l5);

		PrintList(reverseBetween(&l1, 1, 2));
	}

// ============================== 题目94 二叉树构建  [1,null,2,3]
	vector<int> inOrderTraversal(BinaryTreeNode *root) {
		vector<BinaryTreeNode *> stack;
		vector<int> v;

		while (stack.size() > 0 || root != NULL) {
			if (root != NULL) {
				stack.push_back(root);
				root = root->pLeft;
			} else {
				if (stack.size() > 0) {
					root = stack.back();
					stack.pop_back();
					v.push_back(root->value);
					root = root->pRight;
				}
			}
		}
		return v;
	}

// ============================== 题目125 验证回文串
// 清除多余字符，保留 A->Z / a->z / 0->9
	string ClearStr(string s) {
		// 删除
		for (int i = 0; i < s.size(); i++) {
			if ((s[i] - '0' >= 0 && s[i] - '9' <= 0) || (s[i] - 'a' >= 0 && s[i] - 'z' <= 0))
				continue;
			else if ((s[i] - 'A' >= 0 && s[i] - 'Z' <= 0)) {
				s[i] += 'a' - 'A';
			} else {
				s.erase(i, 1);
				i -= 1;
			}
		}
		return s;
	}

	bool isPalindrome(string s) {

		if (s.size() <= 0 || s.size() == 1)
			return false;

		string clearString = ClearStr(s); // 清除 转小写

		// 判断回文
		bool tag = false;
		int n = clearString.size();


		for (int i = 0; i < n / 2; i++) {
			if (clearString[i] == clearString[n - 1 - i])
				continue;
			else {
				return tag;
			}
		}
		tag = true;
		return tag;
	}

	void test_leet125() {
		cout << isPalindrome("12521");
	}

// ============================== 题目151 字符串中，按单词进行反转
	void reverseWords(string &s) {
		bool wordStart = false;
		vector<string> v;

		const char *pHead = s.c_str();
		const char *pStr, *pBegin, *pEnd;

		for (pStr = pHead; *pStr != '\0'; pStr++) {

			if (!isspace(*pStr) && wordStart == false) {
				wordStart = true;
				pBegin = pStr;
				continue;
			} // 词头

			if (isspace(*pStr) && wordStart == true) {
				wordStart = false;
				pEnd = pStr;
				v.insert(v.begin(), s.substr(pBegin - pHead, pEnd - pBegin));
			} // 词尾， 字符串尾部插入
		}

		if (wordStart == true) {
			pEnd = pStr;
			v.insert(v.begin(), s.substr(pBegin - pHead, pEnd - pBegin));
		}

		if (v.size() > 0) {
			s.clear();
			char space = ' ';
			vector<string>::iterator it;
			for (it = v.begin(); it != v.end(); ++it) {
				s = s + *it;
				s.push_back(space);
			}
			s.erase(s.end() - 1);
		} else {
			s.clear();
		}
		cout << "[" << s << "]" << endl;
	}
}
#endif //INTERVIEW_CPP_LEET100_H
