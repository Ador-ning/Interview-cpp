//
// Created by ning on 2018/8/27.
//

#ifndef INTERVIEW_CPP_L1_H
#define INTERVIEW_CPP_L1_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// -------------- 牛客网 算法高频题目 ---------------

// 题1： A B 玩家选数(数组两侧选)  -- 博弈
int s_(vector<int>, int, int);

// 先选过程
int f_(vector<int> arr, int i, int j) {
	if (i == j)
		return arr[i];
	return max(arr[i] + s_(arr, i + 1, j), arr[j] + s_(arr, i, j - 1));
}

// 后选过程
int s_(vector<int> arr, int i, int j) {
	if (i == j)
		return 0;
	// 先选 导致
	return min(f_(arr, i + 1, j), f_(arr, i, j - 1));
}

void win1() {
	vector<int> arr = {5, 2, 3, 4, 5};
	if (arr.size() <= 0)
		return;
	int sum = 0;
	for (int i = 0; i < arr.size() - 1; i++)
		sum += arr[i];
	int fValue = f_(arr, 0, arr.size() - 1);
	cout << max(fValue, sum - fValue);
	return;
}

// 暴力递归 改 DP  f表 / s表
void win2() {
	vector<int> arr = {5, 2, 3, 4, 5};
	if (arr.size() <= 0)
		return;

	// DP求解 1. i == j return arr[i] 2. arr[i] + s(arr, i+1, j) or arr[j] + s(arr, i, j-1)
	vector<vector<int>> f(arr.size(), vector<int>(arr.size(), 0));
	vector<vector<int>> s(arr.size(), vector<int>(arr.size(), 0));

	for (int j = 0; j < arr.size(); j++) {
		f[j][j] = arr[j]; // 初始化
		for (int i = j - 1; i >= 0; i--) {
			f[i][j] = max(arr[i] + s[i + 1][j], arr[j] + s[i][j - 1]);
			s[i][j] = min(f[i + 1][j], f[i][j - 1]);
		}
	}

	cout << f[0][arr.size() - 1] << ' ' << s[0][arr.size() - 1];
	return;
}

// 改递归 一个选择
int p_(vector<int> arr, int i, int j) {
	if (i == j)
		return arr[i];
	if ((i + 1) == j)
		return max(arr[i], arr[j]);
	return max(
			// i+1 -> j
			arr[i] + min(p_(arr, i + 2, j), p_(arr, i + 1, j - 1)),
			// i -> j-1
			arr[j] + min(p_(arr, i, j - 2), p_(arr, i + 1, j - 1)));
}

// 题2：判断括号有效性
bool isValid1(const string s) {
	if (s.size() <= 0)
		return false;
	int status = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ')' && s[i] != '(')
			return false; // 其他字符
		if (s[i] == ')' && --status < 0)
			return false;
		if (s[i] == '(')
			status++;
	}

	return status == 0;
}

// 进阶：返回 最长有效括号长度 -- dp解  ()(()())
/*
i    0  1   2   3   4   5   6   7
     (  )   (   (   )   (   )   )
dp[] 0  2   0   0   2   0   4   (6+2)
 */
int maxLengthString(string s) {
	if (s.size() <= 0)
		return 0;
	vector<int> dp(s.size(), 0); // '(' -> 0
	int pre = 0;
	int res = 0;

	cout << "Test: " << endl;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ')') { // 情况 配对
			pre = i - dp[i - 1] - 1; // pre --> dp[i-1] -- 指定匹配的 '('位置
			if (pre >= 0 && s[pre] == '(') {
				dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0); //
			}
			cout << "i: " << i << " pre: " << pre << " dp[i] " << dp[i] << endl;
		}
		res = max(dp[i], res);
	}
	return res;
}

// 题3：给定一个数组，值全是正数，请返回累加和为给定值k的最长子数组长度

#endif //INTERVIEW_CPP_L1_H
