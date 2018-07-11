//
// Created by ning on 2018/7/1.
//

#ifndef INTERVIEW_CPP_GRAP_H
#define INTERVIEW_CPP_GRAP_H

#include <iostream>
#include <queue>

using namespace std;

#define N 15

class Node {
	int v;  // 连接点编号
	int w;  // 权值

	Node() : v(0), w(0) {}

	Node(int i, int j) : v(i), w(j) {}
};

vector<int> Adj[N]; // 图邻接表存储  N 个结点
bool visit[N] = {false}; // 访问标志    DFS
bool inq[N] = {false}; // 入队列标志    BFS

// ======================= 图遍历 ======================= //
void DFS(int u, int depth) {
	visit[u] = true;
	// 对 u 操作
	for (int i = 0; i < Adj[u].size(); i++) {
		int v = Adj[u][i];
		if (visit[v] == false)
			DFS(v, depth + 1);
	}
}

void DfsTrave() {
	for (int u = 0; u < N; u++) {
		if (visit[u] == false)
			DFS(u, 1);
	}
}

void BFS(int u) {
	queue<int> q;
	q.push(u);
	inq[u] = true;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < Adj[u].size(); i++) {

			int v = Adj[u][i];  // 邻接结点编号

			if (inq[v] == false) {
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

void BfsTrave() {
	for (int u = 0; u < N; u++) {
		if (inq[u] == false)
			BFS(u); // 遍历u所在的连通块
	}
}

// ======================= 最短路径 ======================= //

#endif //INTERVIEW_CPP_GRAP_H
