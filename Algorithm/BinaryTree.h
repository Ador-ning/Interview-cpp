//
// Created by ning on 2018/5/23.
//

#ifndef INTERVIEW_CPP_BINARYTREE_H
#define INTERVIEW_CPP_BINARYTREE_H

#include <iostream>

using namespace std;

struct BinaryTreeNode {
	int value;
	BinaryTreeNode *pLeft;
	BinaryTreeNode *pRight;
};

// 创建结点
BinaryTreeNode *CreateBinaryTreeNode(int value) {
	BinaryTreeNode *pNode = new BinaryTreeNode();
	pNode->value = value;
	pNode->pLeft = nullptr;
	pNode->pRight = nullptr;

	return pNode;
}

// 连接结点
void ConnectBinaryNodes(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight) {
	if (pParent != nullptr) {
		pParent->pRight = pRight;
		pParent->pLeft = pLeft;
	}
}

// 打印结点
void PrintTreeNode(const BinaryTreeNode *pNode) {
	if (pNode != nullptr) {
		cout << "Value of its node is :" << pNode->value << "." << endl;

		if (pNode->pLeft != nullptr)
			cout << "Value of its left child is :" << pNode->pLeft->value << "." << endl;
		else
			cout << " No left child." << endl;

		if (pNode->pRight != nullptr)
			cout << "Value of its right child is :" << pNode->pRight->value << "." << endl;
		else
			cout << " No right child." << endl;
	} else {
		cout << "This node is nullptr." << endl;
	}
	cout << endl;
}

// 打印树 -- 先序
void PrintTree(const BinaryTreeNode *pRoot) {
	if (pRoot != nullptr) {
		if (pRoot->pLeft != nullptr)
			PrintTree(pRoot->pLeft);

		if (pRoot->pRight != nullptr)
			PrintTree(pRoot->pRight);
	}
}

// 删除树
void DestroyTree(BinaryTreeNode *pRoot) {
	if (pRoot != nullptr) {
		BinaryTreeNode *pLeft = pRoot->pLeft;
		BinaryTreeNode *pRight = pRoot->pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}


#endif //INTERVIEW_CPP_BINARYTREE_H
