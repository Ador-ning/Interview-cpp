//
// Created by ning on 2018/7/13.
//

#ifndef INTERVIEW_CPP_DP2_H
#define INTERVIEW_CPP_DP2_H

#include <iostream>

using namespace std;

namespace Leetcode {
# define MAX 101
	// ============================== 数字三角 数字三角形中寻找一条从顶部到底边的路径，使得路径上所经过的数字之和最大。路径上的每一步都只能往左下或 右下走。只需要求出这个最大和即可，不必给出具体路径
	int D[MAX][MAX];
	int maxSum[MAX][MAX];
	int row; // 行数

	// 递归
	int MaxSum_recurr(int i, int j) {
		if (i == n)
			return D[i][j]; // 自上而下

		int x = MaxSum_recurr(i + 1, j);
		int y = MaxSum_recurr(i + 1, j + 1);
		return max(x, y) + D[i][j];
	}

	// 递归 -- 记忆型
	int MaxSUM_recurr2(int i, int j) {
		if (maxSum[i][j] != -1)
			return maxSum[i][j];    // maxSum 初始化为 -1
		if (i == n)
			maxSum[i][j] = D[i][j];
		else {
			int x = MaxSUM_recurr2(i + 1, j);
			int y = MaxSum_recurr2(i + 1, j + 1);
			maxSum[i][j] = max(x, y) + D[i][j];
		}
		return maxSum[i][j];
	}

	// 自底向上，一次性求得结果
	void dp_MaxSum() {
		int i, j;
		cin >> row;

		for (i = 1; i <= n; i++)
			for (j = 1; j <= i; j++)
				cin >> D[i][j];

		for (int i = 1; i <= n; i++)
			maxSum[n][i] = D[n][i]; // 底

		for (int i = n - 1; i >= 1; i--) {
			for (int j = 1; j <= i; j++) {
				maxSum[i][j] = D[i][j] + max(maxSum[i + 1][j], maxSum[i + 1][j + 1]);
			}
		}

		cout << maxSum[1][1];
	}

	// ============================== 字符交错
	/*
Considering:
    s1 = a1, a2 ........a(i-1), ai
    s2 = b1, b2, .......b(j-1), bj
    s3 = c1, c3, .......c(i+j-1), c(i+j)
Defined:
    match[i][j]  means   s1[0..i] and s2[0..j] is matched S3[0..i+j]
    So, if ai == c(i+j), then match[i][j] = match[i-1][j], which means
        s1 = a1, a2 ........a(i-1)
        s2 = b1, b2, .......b(j-1), bj
        s3 = c1, c3, .......c(i+j-1)
    Same, if bj = c(i+j), then match[i][j] = match[i][j-1];
Formula:
    Match[i][j] =
        (s3[i+j-1] == s1[i]) && match[i-1][j] ||
        (s3[i+j-1] == s2[j]) && match[i][j-1]
Initialization:
    i=0 && j=0, match[0][0] = true;
    i=0,   s3[j] == s2[j], match[0][j] |= match[0][j-1]
           s3[j] != s2[j], match[0][j] = false;
    j=0,   s3[i] == s1[i], match[i][0] |= match[i-1][0]
           s3[i] != s1[i], Match[i][0] = false;
*/
	bool isInterLeave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())
			return false;

		vector<vector<int>> match(s1.size() + 1, vector<int>(s2.size() + 1, false));
		match[0][0] = true;

		for (int i = 1; i <= s1.size(); i++) {
			if (s1[i - 1] == s3[i - 1])
				match[i][0] = true;
			else
				break;
		}
		for (int i = 1; i <= s2.size(); i++) {
			if (s2[i - 1] == s3[i - 1])
				match[0][i] = true;
			else
				break;
		} // 初始边界

		for (int i = 1; i <= s1.size(); i++) {
			for (int j = 0; j <= s2.size(); j++) {
				if (s1[i - 1] == s3[i + j - 1])
					match[i][j] = match[i - 1][j] || match[i][j];

				if (s2[j - 1] == s3[i + j - 1])
					match[i][j] = match[i][j - 1] || match[i][j];
			}
		}
		return match[s1.size()][s2.size()];
	}
}
#endif //INTERVIEW_CPP_DP2_H

