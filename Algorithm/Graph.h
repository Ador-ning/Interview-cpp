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
public:
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
// Dijkstra
const int MAXV = 1000;
const int INF = 1000000000;

vector<Node> Adj2[MAXV]; //
int n; // 顶点数
int d[MAXV]; // 起点到达各点的最短路径
bool visit2[MAXV] = {false};

void Dijkstra(int s) {
	fill(d, d + MAXV, INF); // INF填充
	d[s] = 0; // 到达自身距离
	for (int i = 0; i < n; i++) {
		int u = -1; // u 使 d[u]最小，MIN 存放该最小的 d[u]
		int MIN = INF;

		for (int j = 0; j < n; j++) { // 找到未访问的顶点中 d[] 最小的
			if (visit2[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}

		// 找不到小于 INF 的 d[u], 说明剩下的顶点和 s 不连通
		if (u == -1)
			return;

		visit2[u] = true;   // 标记 u 已访问

		for (int j = 0; j < Adj2[u].size(); j++) {
			int v = Adj2[u][j].v;    // 通过邻接表直接获取 u 能到达的顶点 v

			if (visit2[v] == false && d[u] + Adj2[u][j].w < d[v]) {
				// v未访问  // u 为中介可以使 d[v]更优
				d[v] = d[u] + Adj2[u][j].w;
			}
		}
	}
}


#endif //INTERVIEW_CPP_GRAP_H
