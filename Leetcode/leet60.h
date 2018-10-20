//
// Created by ning on 2018/6/26.
//

#ifndef INTERVIEW_CPP_LEET60_H
#define INTERVIEW_CPP_LEET60_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

namespace Leetcode {
#define MAX_INT (pow(2, 31))
#define MIN_INT (-pow(2, 31) - 1)

	class Interval {
	public:
		Interval() : left(0), right(0) {}

		Interval(int s, int e) : left(s), right(e) {}

		int left;
		int right;
	};

	// ============================== 题目41  数字字符串 乘法
	string strPlus(string &nums1, string &nums2) {
		if (nums1.size() == 0)
			return nums2;
		if (nums2.size() == 0)
			return nums1;

		if (nums1.size() < nums2.size())
			swap(nums1, nums2);

		string s;
		int carray = 0;
		int x;

		for (int i = nums1.size() - 1, j = nums2.size() - 1; i >= 0; i--, j--) {
			x = nums1[i] - '0' + carray;
			if (j >= 0)
				x += nums2[j] - '0';
			s.insert(s.begin(), x % 10 + '0');
			carray = x / 10;
		}

		if (carray > 0)
			s.insert(s.begin(), carray + '0');

		return s;
	}

	string multiply(string num1, string num2) {
		if (num1.size() <= 0 || num2.size() <= 0)
			return "";

		string result;

		for (int i = num1.size() - 1; i >= 0; --i) {
			int carry = 0;
			string val;

			for (int j = num2.size() - 1; j >= 0; --j) {
				int v = (num2[j] - '0') * (num1[i] - '0') + carry;
				val.insert(val.begin(), v % 10 + '0');
				carry = v / 10; // 进位
			}
			if (carry)
				val.insert(val.begin(), carry + '0');
			for (unsigned int j = i; j < num1.size() - 1; j++)
				val.push_back('0');
			result = strPlus(result, val); // 加法
		}
		if (result[0] == '0')
			return "0";
		return result;
	}

	void test_leet41() {
		string s1 = "12";
		string s2 = "6";
		cout << multiply(s1, s2) << endl;
	}

	// ============================== 题目46 全排列1，候选数字不重复
	vector<vector<int>> permute_alg(vector<int> &num) {
		vector<vector<int>> vv;
		vv.push_back(num);

		if (num.size() < 2)
			return vv;

		int pos = 0;

		while (pos <= num.size() - 1) {
			int size = vv.size();

			for (int i = 0; i < size; ++i) { // 对已有的结果，调整

				for (int j = pos + 1; j < vv[i].size(); ++j) {
					vector<int> v = vv[i];

					int t = v[j];
					v[j] = v[pos];
					v[pos] = t; // 交换 pos - j for each

					vv.push_back(v);
				}
			}
			pos++;
		}
		return vv;
	}

	void test_leet46() {
		vector<int> n = {1, 2, 3};
		permute(n);
	}

	// ============================== 题目48 矩阵顺时针旋转 90度
	void rotate(vector<vector<int>> &matrix) {
		int n = matrix.size();

		for (int i = 0; i < n / 2; i++) {

			int low = i, high = n - i - 1;

			for (int j = low; j < high; j++) {
				int tmp = matrix[i][j];

				// left to top
				matrix[i][j] = matrix[n - j - 1][i];
				// bottom to left
				matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
				// right to bottom
				matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
				// top to right
				matrix[j][n - i - 1] = tmp;
			}
		}
	}


	// ============================== 题目49
	bool Anagrams(string &s1, string &s2) {
		if (s1.size() != s2.size())
			return false;
		for (int i = 0; i < s1.size(); ++i) {
			if (s2.find(s1[i]) >= s2.size() || s2.find(s1[i]) < 0) // 不存在时，返回结果
				return false;
		}
		return true;
	}

	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		vector<vector<string>> result;
		int StrsLen = strs.size();

		if (StrsLen <= 1)
			return result;

		int work[StrsLen]; // 0 表示字符串没有使用
		for (int i = 0; i < StrsLen; ++i)
			work[i] = 0;

		for (int i = 0; i < StrsLen; ++i) {

			if (work[i] == 1) // 表示已经归类
				continue;
			else {
				vector<string> val;
				val.push_back(strs[i]);

				cout << strs[i] << '\t';

				for (int j = i + 1; j < strs.size(); ++j) {
					if (Anagrams(strs[i], strs[j])) { // 判断 字母异位词
						val.push_back(val[j]);
						work[j] = 1;
						cout << strs[j] << '\t';
					}
				}

				result.push_back(val);
				cout << endl;
			}
		}
		return result;
	}

	void test_leet49() {
		vector<string> s = {"eat", "eat", "tan", "ate", "nat", "bat"};

		groupAnagrams(s);
	}

	// ============================== 题目50 pow

	double myPow(double x, int n) {

		if (x == 0.0)
			return 0.0;
		if (x == 1.0)
			return 1.0;
		if (n == 0)
			return 1.0;
		if (x > 100.0 || x < -100.0)
			return 0.0;

		if (x == -1.0)
			if (n % 2 == 0)
				return 1.0;
			else
				return -1.0;

		if (n > MAX_INT || n < MIN_INT)
			return 0.0;


		if (n < 0) {
			x = 1 / x;
			n = -n;
		}
		double t = x;
		for (int i = 0; i < n - 1; ++i)
			t *= x;

		return t;
	}

	void test_leet50() {
		cout << myPow(2.5, 5544);
	}

	// ============================== 题目55
	bool canJump(vector<int> &nums) {
		int n = nums.size();
		if (n <= 0)
			return false;

	}

	void test_leet55() {
		vector<int> n = {2, 3, 1, 1, 4}; // 3,2,1,0,4
		cout << canJump(n) << endl;
	}

	// ============================== 题目56 Merge intervals
	bool sortIntervals(const Interval &i1, const Interval &i2) {
		return i1.left < i2.left; // 升序
	}

	vector<Interval> merge(vector<Interval> &intervals) {
		// 1. 对 left排序 升序
		// 2. 合并 -- 合并条件
		int n = intervals.size();
		vector<Interval> result;

		if (n <= 0)
			return result;

		// 排序
		sort(intervals.begin(), intervals.end(), sortIntervals);
		// 合并
		Interval tmp = intervals[0];
		for (int i = 1; i < n; i++) {
			if (intervals[i].left <= tmp.right) { // 合并
				tmp.right = tmp.right > intervals[i].right ? tmp.right : intervals[i].right;
			} else {
				result.push_back(tmp); // 保存
				tmp = intervals[i]; // 更新
			}
		}
		return result;
	}

	void test_leet56() {
		Interval i1(1, 3);
		Interval i2(2, 6);
		Interval i3(8, 10);
		Interval i4(15, 18);

		vector<Interval> v = {i1, i2, i3, i4};
	}

	// ============================== 题目60 全排列中第k个排列
	string getPermutation(int n, int k) {

		if (n <= 0 || k <= 0)
			return "";
		if (n == 1 && k == 1)
			return "1";

		vector<int> nums;
		for (int i = 1; i <= n; ++i)
			nums.push_back(i);
	}

}
#endif //INTERVIEW_CPP_LEET60_H
