//
// Created by ning on 2018/6/30.
//

#ifndef INTERVIEW_CPP_AVL_H
#define INTERVIEW_CPP_AVL_H

#include "BinaryTree.h"

using namespace std;


struct AvlNode {
	int value;
	int height;
	AvlNode *lChild;
	AvlNode *rChild;

	AvlNode() : value(0), height(0), lChild(nullptr), rChild(nullptr) {}

	AvlNode(int x) : value(x), height(0), lChild(nullptr), rChild(nullptr) {}

	AvlNode(int x, int h) : value(x), height(h), lChild(nullptr), rChild(nullptr) {}
};

// =========================== base operation =========================== //
// 获取以 pRoot 为根结点的子树的当前 height
int getHeight(AvlNode *pRoot) {
	if (pRoot == nullptr)
		return 0;
	return pRoot->height;
}

// 计算结点 pRoot 的平衡因子
int getBalance(AvlNode *pRoot) {
	return getHeight(pRoot->lChild) - getHeight(pRoot->rChild);
}

// 更新结点 pRoot height
void updateHeight(AvlNode *pRoot) {
	pRoot->height = max(getHeight(pRoot->rChild), getHeight(pRoot->lChild));
}

// 查找
void AvlSearch(AvlNode *pRoot, int x) {
	if (pRoot == nullptr) {
		cout << "Search failed." << endl;
		return;
	}

	if (x == pRoot->value)
		cout << pRoot->value << endl;
	else if (x < pRoot->value)
		AvlSearch(pRoot->lChild, x);
	else
		AvlSearch(pRoot->rChild, x);
}

// 左旋操作 left rotation
void L(AvlNode *&pRoot) {
	AvlNode *tmp = pRoot->rChild;

	pRoot->rChild = tmp->lChild; // 步骤1
	tmp->lChild = pRoot; // 步骤2

	updateHeight(pRoot); // 更新结点 A 的高度
	updateHeight(tmp); // 更新结点 B 的高度
	pRoot = tmp; // 步骤3
}

// 右旋操作 right rotation
void R(AvlNode *&pRoot) {
	AvlNode *tmp = pRoot->lChild;

	pRoot->lChild = tmp->rChild; // 步骤1
	tmp->rChild = pRoot; // 步骤2

	updateHeight(pRoot); // 更新结点 A 的高度
	updateHeight(tmp); // 更新结点 B 的高度
	pRoot = tmp; // 步骤3
}

#endif //INTERVIEW_CPP_AVL_H
