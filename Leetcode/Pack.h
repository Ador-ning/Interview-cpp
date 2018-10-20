//
// Created by ning on 2018/7/17.
//

#ifndef INTERVIEW_CPP_PACK_H
#define INTERVIEW_CPP_PACK_H

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

namespace Leetcode {
#define  maxV 100

// 背包九讲
// 1. 01背包
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
						// 递减 -- 暂存数据，只是上一次， 故而可以省空间
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

// 2. 完全背包  -- 物品不按件数
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

// 3. 多重背包 -- 第i个物品 最多 Mi个
	int f[maxV], v;

	void ZeroOnePack(int ci, int wi) {
		for (int j = v; j >= ci; j--)   // v -> ci
			f[j] = max(f[j], f[j - ci] + wi);
	}

	void CompletePack(int ci, int wi) {
		for (int j = ci; j <= v; j++)   // ci -> v
			f[j] = max(f[j], f[j - ci] + wi);
	}

	void MultiplePack(int mi, int ci, int wi) {
		if (mi * ci >= v) {
			cout << "Complete Pack." << endl;
			CompletePack(ci, wi);
			return;
		}

		int k = 1;
		int M = mi;
		while (k < M) {
			cout << "K: " << k << "M: " << M << '\t';
			ZeroOnePack(ci * k, wi * k);
			M -= k;
			k *= 2;
		}
		cout << endl;
		cout << endl;
		cout << "K: " << k << '\t' << "M: " << M << endl;
		ZeroOnePack(ci * M, wi * M);
	}

	void pack_multi() {
		int times, n, mi, ci, wi;
		cin >> times;
		while (times--) {
			memset(f, 0, sizeof(f));
			cin >> n >> v;

			for (int i = 0; i < n; i++) {
				cin >> mi >> ci >> wi;
				MultiplePack(mi, ci, wi);
				cout << "N: " << n << endl;
				cout << "results: ";
				for (int i = 0; i <= v; i++)
					cout << f[i] << '\t';
				cout << endl;
			}

			cout << "All Results: ";
			for (int i = 0; i <= v; i++)
				cout << f[i] << '\t';
			cout << endl;
			cout << "Final Result: " << f[v] << endl;
		}
	}

// 4. 混合背包
	void pack_complex() {
		int times, n, mi, ci, wi;
		cin >> times;
		while (times--) {
			memset(f, 0, sizeof(f));

			cin >> n >> v;

			for (int i = 0; i < n; i++) {
				cin >> mi >> ci >> wi;
				if (mi == 1)
					ZeroOnePack(ci, wi);
				else if (mi == -1)
					CompletePack(ci, wi);
				else
					MultiplePack(mi, ci, wi);
			}

			cout << "All Results: ";
			for (int i = 0; i <= v; i++)
				cout << f[i] << '\t';
			cout << endl;
			cout << "Final Result: " << f[v] << endl;
		}
	}

// 5. 二维费用的背包
	void pack_twoDim() {
		int times, n, v, u, ai, bi, wi;
		int f[maxV][maxV];

		cin >> times;

		while (times--) {
			memset(f, 0, sizeof(f));
			cin >> n >> v >> u;
			for (int i = 0; i < n; i++) {
				cin >> ai >> bi >> wi;
				for (int j = v; j >= ai; j--)
					for (int k = u; k >= bi; k--) {
						f[j][k] = max(f[j][k], f[j - ai][k - bi] + wi);
					}
			}
			cout << f[v][u] << endl;
		}
	}

// 6. 分组背包  -- 物品被划分为 K 组， 每组中的物品冲突，只能选一件
	void pack_group() {
		int times, n, v, g, gi;
		f[maxV];
		int ci[maxV], wi[maxV];

		cin >> times;
		while (times--) {
			memset(f, 0, sizeof(f));
			cin >> n >> v >> g;
			vector<vector<int>> gMap;
			for (int i = 0; i < n; i++) {
				cin >> ci[i] >> wi[i] >> gi;
				gMap[gi].push_back(i);  // 记录分组信息
			}

			for (int i = 0; i < g; i++) {
				for (int j = v; j >= 0; j--) {
					for (int k = 0; k < gMap[i].size(); k++)
						if (j >= ci[gMap[i][k]])    // i 组 k 个
							f[j] = max(f[j], f[j - ci[gMap[i][k]]] + wi[gMap[i][k]]);
				}
			}

			cout << f[v] << endl;
		}
	}
}
#endif //INTERVIEW_CPP_PACK_H
