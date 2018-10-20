//
// Created by ning on 2018/7/13.
//

#ifndef INTERVIEW_CPP_DP_H
#define INTERVIEW_CPP_DP_H

#include <iostream>

using namespace std;

namespace Leetcode {
	// ============================== 1元 3元 5元硬币，如何用最少的硬币凑11元？
	void dp1() {
		int cons[3] = {1, 3, 5};

		int value;
		while (cin >> value) {
			int *arr = new int[value];

			arr[0] = 0;
			for (int i = 1; i <= value; i++) {
				int cons1 = i - 1;
				int cons3 = i - 3;
				int cons5 = i - 5;  // 一次， 剩余的钱数 // 前面有结果

				// 状态转移方程 d(i) = min{d(i-vj)+1}, vj是第j个硬币币值
				int minConsSum = arr[cons1];    // 1元
				int lastCons = cons1;

				// 3元
				if (cons3 >= 0 && arr[cons3] < minConsSum) {
					minConsSum = arr[cons3];
					lastCons = cons3;
				}

				// 5元
				if (cons5 >= 0 && arr[cons5] < minConsSum) {
					minConsSum = arr[cons5];
					lastCons = cons5;
				}

				// 赋值
				arr[i] = minConsSum + 1;

				cout << i << '\t' << arr[i] << '\t' << lastCons << endl;
			}

			cout << endl;
		}
	}

	// ============================== 一个序列有N个数：A[1],A[2],…,A[N]，求出最 长非降子序列的长度.  Longest increasing sub-sequence  -- LIS问题
	// 递推关系来将状态联系起来  ===========  初级问题
	// d(i) = max{1, d(j) + 1}, j<i , A[j] < A[i]
	void dp_lis() {
		vector<int> nums = {5, 3, 4, 8, 6, 7};

		int *d = new int[nums.size()];  // 存数据
		int len = 1; // 记录长度

		for (int i = 0; i < nums.size(); i++) {
			d[i] = 1; // 初始

			for (int j = 0; j < i; j++) {
				if (nums[j] <= nums[i] && d[j] + 1 > d[i]) // 递推关系
					d[i] = d[j] + 1;
			}

			if (d[i] > len)
				len = d[i]; // 更新
		}

		delete[] d;

		for (int i = 0; i < nums.size(); i++)
			cout << d[i] << '\t';
		cout << endl;

		cout << "LIS length: " << len << endl;
	}

	// ============================== 二维DP  N * M 格子，每个格子中放着一定数量的苹果
	// 递推公式： S[i][j] = A[i][j] + max{S[i-1][j], S[i][j-1]} // 不越界
	void MostAppleCollected(int **A, int n, int m) {
		int **s = new int *[n];
		for (int i = 0; i < n; i++)
			s[i] = new int[m]; // 辅助记录

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int left = 0;
				int up = 0;

				if (i > 0)
					up = s[i - 1][j];
				if (j > 0)
					left = s[i][j - 1];
				int neighbor = left >= up ? left : up;
				s[i][j] = neighbor + A[i][j];
			}
		}
		int result = s[n - 1][m - 1];

		for (int i = 0; i < n; i++)
			delete[]s[i];
		delete[]s;
		cout << result << endl;
	}

	// ============================== 带额外条件的DP问题

}

#endif //INTERVIEW_CPP_DP_H
