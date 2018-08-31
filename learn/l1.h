//
// Created by ning on 2018/8/27.
//

#ifndef INTERVIEW_CPP_L1_H
#define INTERVIEW_CPP_L1_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 子串子数组问题 -- 以某位置开头/结尾
 子序列问题 --
 */

// -------------- 牛客网 算法高频题目 ---------------
// #### 课1 -- 第四个视频 40 分钟位置
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
void sumK(const vector<int> arr, int k) {
	if (arr.size() <= 0 || k <= 0)
		return;
	// 子数组连续
	// 窗口
	int res = 0;
	int i = 0;
	int sum = 0; // sum of arr[i ... j-1]
	for (int j = 0; j < arr.size(); ++j) {
		sum += arr[j];

		while (sum > k) {
			sum -= arr[i];
			++i;
		} // change i make sum <= k
		// cout << "change i: " << i << " sum: " << sum << endl;
		if (sum == k) {
			cout << j << ' ' << i << endl;
			if ((j - i + 1) > res)
				res = j - i + 1;
		}
	}

	cout << res << endl;
}

// 进阶1：数组值 可以为 正、负、零 --> 转化为：求 sum = arr[0 -> j], sum-k = arr[0 -> i] , map表
void sumK1(const vector<int> arr, int k) {
	if (arr.size() <= 0)
		return;
	map<int, int> m;
	m.insert(make_pair(0, -1));
	int len = 0;
	int sum = 0;
	for (int i = 0; i < arr.size(); ++i) {
		sum += arr[i];
		if (m.find(sum - k) != m.end())
			len = max(len, i - m[sum - k]);
		if (m.find(sum) == m.end())
			m.insert(make_pair(sum, i));
	}
	cout << len;
}

// 进阶2： 进阶1 中，变小于等于k
/*         0  1   2  3  4   5   6
 arr:      4  3  -2  6  7  -3  -1
min_sum:   4  1  -2  6  3  -4  -1  从该位置向右 子数组最小和
min_index: 0  2   2  3  6   6   6  和最小子数组 右边界
 */
// 题4： 设计一个针对全球的、访问量极大的id生成系统。必须保证用户每次从该系统得到的id是唯一的，而且在概率上毫无碰撞可能。

// #### 课2：
// 题1：栈中元素逆置，只能通过递归实现
int helperReverse(stack<int> &s) { // 移除栈底元素，其他不变
	int result = s.top();
	s.pop();
	if (s.empty())
		return result; // 返回 --> last
	else {
		int last = helperReverse(s);
		s.push(result);
		return last;
	}
}

void reverseStack(const vector<int> arr) {
	if (arr.size() <= 0)
		return;

	stack<int> s;
	for (int i = 0; i < arr.size(); ++i)
		s.push(arr[i]);
	helperReverse(s);
}

// 题2：最小数组和
// O(n2)
void minSummaryArr(const vector<int> arr) {
	if (arr.size() <= 0)
		return;

	int res = 0;
	int k = 0;
	for (int i = 0; i < arr.size(); ++i) {
		while (k < i) {
			if (arr[k] < arr[i])
				res += arr[k];
			++k;
		}
		k = 0; // 优化
	}
	cout << res << endl;
}
// O(n.logn) -- merge sort

// 题3： 给定一个数组arr，返回子数组的最大累加和
void maxSumArr(const vector<int> arr) {
	if (arr.size() <= 0)
		return;

	vector<int> dp(arr.size(), 0);
	dp[0] = arr[0];
	int res = 0;
	for (int i = 1; i < arr.size(); ++i) {
		if (dp[i - 1] > 0)
			dp[i] = arr[i] + dp[i - 1];
		else
			dp[i] = arr[i]; // ##

		if (dp[i] > res)
			res = dp[i];
	}

	for (int i = 0; i < dp.size(); ++i)
		cout << dp[i] << ' ';
	cout << endl;
	cout << res << endl;
}

// 题4：生成ID

// #### 课3：
// 题1：

// 题2： 二维数组 0/1 -> BFS,  求岛数量
void countIsland(const vector<vector<int>> arr) {
	if (arr.size() <= 0)
		return;

}

// 题3： 二维矩阵 最大子矩阵和

// #### 课4：

#endif //INTERVIEW_CPP_L1_H
