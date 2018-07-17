//
// Created by ning on 2018/7/17.
//

#ifndef INTERVIEW_CPP_PACK_H
#define INTERVIEW_CPP_PACK_H

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define  maxV 100

// 背包九讲
// 01背包
void pack_01() {
	int times, n, v, ci, wi;

	int f[maxV];
	cin >> times;
	while (times--) {
		memset(f, 0, sizeof(f));

		cin >> n >> v;

		for (int i = 0; i < n; i++) {
			cin >> ci >> wi;    // cost weight
			for (int j = v; j >= 0; j--) { // v -> ci
				if (j >= ci)
					f[j] = max(f[j - ci] + wi, f[j]); // 状态转移方程
			}
			cout << "N :" << i << '\t';
			cout << "f[]: ";
			for (int k = 0; k <= v; k++)
				cout << f[k] << '\t';
			cout << endl;
		}

		cout << "All Results: ";
		for (int i = 0; i <= v; i++)
			cout << f[i] << '\t';
		cout << endl;
		cout << "Final Result: " << f[v] << endl;
	}
}

// 完全背包  -- 物品不按件数
void pack_complete() {
	int times, n, v, ci, wi;

	int f[maxV];
	cin >> times;
	while (times--) {
		memset(f, 0, sizeof(f));

		cin >> n >> v;

		for (int i = 0; i < n; i++) {
			cin >> ci >> wi;    // cost weight
			for (int j = 0; j <= v; j++) { // ci -> v       #######
				if (j >= ci)
					// f[j-ci] + wi  -- 自动多个选择
					f[j] = max(f[j - ci] + wi, f[j]); // 状态转移方程
			}
			cout << "N :" << i << '\t';
			cout << "f[]: ";
			for (int k = 0; k <= v; k++)
				cout << f[k] << '\t';
			cout << endl;
		}

		cout << "All Results: ";
		for (int i = 0; i <= v; i++)
			cout << f[i] << '\t';
		cout << endl;
		cout << "Final Result: " << f[v] << endl;
	}
}

#endif //INTERVIEW_CPP_PACK_H
