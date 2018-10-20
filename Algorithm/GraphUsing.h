//
// Created by ning on 2018/7/11.
//

#ifndef INTERVIEW_CPP_GRAPHUSING_H
#define INTERVIEW_CPP_GRAPHUSING_H

#include <map>
#include <iostream>
#include <string>

using namespace std;

namespace Algorithm {
/*
 * 题目描述：给出若干人之间的通话长度（视为无向边），这些通话将他们分为若干组。每个组的
 * 总边权设为该组内的所有通话的长度之和，而每个人的点权设为该人参与的通话长度之和。现在
 * 给定一个阈值 K，且只要一个组的总边权超过 K，而且成员人数超过2，将该组视为犯罪团伙（Gang）
 * ,而且该组内点权最大的人视为头目。
 *
 * 要求：输出犯罪团伙的个数，并且按照姓名字典从小到大的顺序输出每个犯罪团伙的头目姓名和
 * 成员人数
 */
	const int maxn = 2010;
	const int INF = 1000000000;

	map<int, string> intToString; // 编号->姓名
	map<string, int> stringToInt; // 姓名->编号
	map<string, int> Gang; // head->人数   输出

	int G[maxn][maxn] = {0}; // 邻接矩阵
	int weight[maxn] = {0}; // 点权
	bool visit[maxn] = {false};
	int n, k, numPerson = 0;    // 边数n、下限k、总人数 numPerson

	void DFS(int nowVisit, int &head, int &numMember, int &totalValue) {
		numMember++;
		visit[nowVisit] = true;

		if (weight[nowVisit] > weight[head])    // 头目  --   点权
			head = nowVisit;
		// 枚举所有人
		for (int i = 0; i < numPerson; i++) {
			if (G[nowVisit][i] > 0) { // nowVisit -> i  通话
				totalValue += G[nowVisit][i];
				G[nowVisit][i] = G[i][nowVisit] = 0;    // 清除

				if (visit[i] == false)  // 深度递归搜索
					DFS(i, head, numMember, totalValue);
			}
		}
	}

	void DFStrave() {
		for (int i = 0; i < numPerson; i++) {
			if (visit[i] == false) {
				int head = 0;
				int numMember = 0;
				int totalNumber = 0;
				DFS(i, head, numMember, totalNumber);   // 遍历 i 连通块

				if (numMember > 2 && totalNumber > k) {
					Gang[intToString[head]] = numMember;
				}
			}
		}
	}

// 返回 姓名 str对应的编号
	int change(string str) {
		if (stringToInt.find(str) != stringToInt.end()) { // 姓名出现过
			return stringToInt[str];
		} else {
			stringToInt[str] = numPerson; // str -> numPerson
			intToString[numPerson] = str;
			return numPerson++; // 总人数++
		}
	}

	int test_Gang() {
		int w;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> str1 >> str2 >> w;   // 端点 权值
			int id1 = stringToInt(str1);
			int id2 = stringToInt(str2);
			weight[id1] += w;
			weight[id2] += w;
			G[id1][id2] = w;
			G[id2][id1] = w;
		}

		DFStrave();
		cout << Gang.size() << endl;

		map<string, int>::iterator it;

		for (it = Gang.begin(); it != Gang.end(); it++) {
			cout << it->first() << ' ' << it->second() << endl;
		}

		return 0;
	}
}

#endif //INTERVIEW_CPP_GRAPHUSING_H
