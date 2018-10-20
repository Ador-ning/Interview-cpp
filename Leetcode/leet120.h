//
// Created by ning on 2018/7/4.
//

#ifndef INTERVIEW_CPP_120_H
#define INTERVIEW_CPP_120_H

#include <iostream>
#include <sstream>
#include <deque>
#include <queue>
#include <stack>

using namespace std;
namespace Leetcode {
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;

		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};


	class Solution {
	public:
		Solution() {
			srand(time(NULL));
		}

		bool isSymmetric(TreeNode *root) {
			if (root == NULL) return true;
			return isSymmetric(root->left, root->right);
		}

		bool isSymmetric(TreeNode *p, TreeNode *q) {
			if (random() % 2) {
				return isSymmetric1(p, q);
			}
			return isSymmetric2(p, q);
		}

		bool isSymmetric1(TreeNode *p, TreeNode *q) {
			if (p == NULL && q == NULL) return true;
			if (p == NULL || q == NULL) return false;

			return (p->val == q->val) &&
			       isSymmetric(p->left, q->right) &&
			       isSymmetric(p->right, q->left);
		}

		bool isSymmetric2(TreeNode *p, TreeNode *q) {
			queue<TreeNode *> q1;
			queue<TreeNode *> q2;
			q1.push(p);
			q2.push(q);

			while (q1.size() > 0 && q2.size() > 0) {
				TreeNode *p1 = q1.front();
				q1.pop();
				TreeNode *p2 = q2.front();
				q2.pop();
				if (p1 == NULL && p2 == NULL) continue;
				if (p1 == NULL || p2 == NULL) return false;

				if (p1->val != p2->val) return false;

				q1.push(p1->left);
				q2.push(p2->right);

				q1.push(p1->right);
				q2.push(p2->left);

			}
			return true;
		}
	};

// ============================== 题目102 二叉树层序遍历  --- 使用两个队列辅助
	vector<vector<int>> LevelOrder(TreeNode *root) {
		vector<vector<int>> result;

		if (root == nullptr)
			return result;

		deque<TreeNode *> q1;
		q1.push_back(root);

		deque<TreeNode *> q2; // 双队列

		int i = 0;

		while (q1.size() || q2.size()) {

			vector<int> t;
			if (i % 2 == 0) { // 取q1， 放 q2
				while (q1.size()) {
					TreeNode *f = q1.front(); // 取
					q1.pop_front(); // 删除

					t.push_back(f->val);

					if (f->left)
						q2.push_back(f->left);
					if (f->right)
						q2.push_back(f->right);
				}
			} else {    // 取q2，放 q1
				while (q2.size()) {
					TreeNode *f = q2.front(); // 取
					q2.pop_front(); // 删除

					t.push_back(f->val);

					if (f->left)
						q1.push_back(f->left);
					if (f->right)
						q1.push_back(f->right);
				}
			}
			result.push_back(t);
			i += 1;
		}
		return result;
	}

// ============================== 题目129 Sum Root to Leaf -- 本质：根结点到叶节点遍历
// 方法1
	int sumNumbers(TreeNode *root) {
		if (root == nullptr)
			return 0;

		int sum = 0;
		vector<TreeNode *> v;
		v.push_back(root);

		while (v.size() > 0) {
			TreeNode *node = v.back();
			v.pop_back();

			if (node->left) {
				node->left->val += (10 * node->val);
				v.push_back(node->left);
			}

			if (node->right) {
				node->right->val += (10 * node->val);
				v.push_back(node->right);
			}

			if (node->right == nullptr && node->left == nullptr)
				sum += node->val;
		}

		return sum;
	}

// 方法2 -- 先序遍历 递归
	vector<vector<int>> allPath(TreeNode *root) {
		if (root != nullptr) {
			// 根

			// 左
			if (root->left != nullptr)
				allPath(root->left);

			// 右
			if (root->right != nullptr)
				allPath(root->right);

			// 叶子结点
			if (root->right == nullptr && root->left == nullptr) {
				//
			}

		}
	}


// ============================== 题目165 版本号比较 --- 切割字符串 -- streamstring  --- sort
	vector<int> &split(const string &s, char delim, vector<int> &elems) {
		istringstream iss(s);  // 流
		string item;
		while (getline(iss, item, delim)) {
			cout << item << '\t';
			elems.push_back(atoi(item.c_str()));
		}
		return elems;
	}

	vector<int> split(const string &s, char delim) {
		vector<int> elems;
		split(s, delim, elems);
		return elems;
	}

	void rightTrimZero(vector<int> &v) {
		while (v.back() == 0)
			v.pop_back();
	}

	int compareVersion(string version1, string version2) {
		vector<int> v1 = split(version1, '.');
		vector<int> v2 = split(version2, '.');

		rightTrimZero(v1); // 去掉尾部为 0
		rightTrimZero(v2);

		// 同长度部分
		for (int i = 0; i < v1.size() && i < v2.size(); i++) {
			if (v1[i] < v2[i])
				return -1;
			else if (v1[i] > v2[i])
				return 1;
		}

		if (v1.size() > v2.size())
			return 1;
		else if (v1.size() < v2.size())
			return -1;

		return 0;
	}

	void test_leet165() {
		string s1 = "0.0.11.3";
		split(s1, '.');
	}

// ============================== 题目402 Remove K Digits -- 剩余最小
	string removeKdigits(string &num, int k) {
		if (num.size() <= k)
			return "0";

		int left_len = num.size() - k;
		int idx = 0;
		for (int i = 0; i < k; i++) {
			int len = num.size();
			for (int j = 0; j < num.size() - 1; j++) {
				if (num[j] > num[j + 1]) {
					num.erase(j, 1);
					idx = j;
					break;  // always pick the smaller one number
				}
			}
		}

		for (int i = 0; i < num.size(); i++) {
			if (num[i] != '0' || i == num.size()) {
				num.erase(0, i);
				break;
			}
		}

		// 升序情况
		if (num.size() > left_len) {
			num.erase(num.begin() + left_len, num.end());
		}

		if (num.empty())
			num = "0";
		return num;
	}
}

#endif //INTERVIEW_CPP_120_H
