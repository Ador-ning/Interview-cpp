//
// Created by ning on 2018/5/23.
//

#ifndef INTERVIEW_CPP_BINARYTREE_H
#define INTERVIEW_CPP_BINARYTREE_H

#include <iostream>
#include <deque>
#include <fstream>

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

// 同层，按照从左到右顺序. 队列辅助实现
/*
 * 面试32：
 */
void PrintTreeTopBottom(const BinaryTreeNode *pRoot) {
	if (pRoot == nullptr)
		return;

	std::deque<const BinaryTreeNode *> dequeTreeNode;
	dequeTreeNode.push_back(pRoot);

	while (dequeTreeNode.size()) {
		const BinaryTreeNode *pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();

		cout << "%d\t" << pNode->value;
		if (pNode->pLeft)
			dequeTreeNode.push_back(pNode->pLeft);

		if (pNode->pRight)
			dequeTreeNode.push_back(pNode->pRight);
	}
}

// 序列化 / 反序列化 二叉树
/*
 * 面试37：
 */

bool ReadStream(istream &stream, int *number) {
	if (stream.eof())
		return false;

	char buffer[32];
	buffer[0] = '\0';

	char ch;
	stream >> ch;
	int i = 0;

	while (!stream.eof() && ch != ',') {
		buffer[i++] = ch;
		stream >> ch;
	}

	bool isNumeric = false;

	if (i > 0 && buffer[0] != '$') {
		*number = stoi(buffer);
		isNumeric = true;
	}

	return isNumeric;
}

void Serialize(const BinaryTreeNode *pRoot, ostream &stream) {
	if (pRoot == nullptr) {
		stream << "$,";
		return;
	}

	stream << pRoot->value << ',';
	Serialize(pRoot->pLeft, stream);
	Serialize(pRoot->pRight, stream);
}

void Deserialize(BinaryTreeNode **pRoot, istream &stream) {
	int number;
	if (ReadStream(stream, &number)) {
		*pRoot = new BinaryTreeNode();
		(*pRoot)->value = number;
		(*pRoot)->pLeft = nullptr;
		(*pRoot)->pRight = nullptr;

		Deserialize(&((*pRoot)->pLeft), stream);
		Deserialize(&((*pRoot)->pRight), stream);
	}
}

// 二叉树深度
/*
 * 面试55：输入一棵二叉树的根结点，求该树的深度
 * 从根结点到叶结点一次经过的结点（含根、叶结点）形成树的一条路径，最长路径为其深度
 */
int TreeDepth(const BinaryTreeNode *pRoot) {
	if (pRoot == nullptr)   // 空树 或者 叶结点
		return 0;

	int nLeft = TreeDepth(pRoot->pLeft);
	int nRight = TreeDepth(pRoot->pRight);
	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

// BST树 -- 二叉搜索树的第K个结点
/*
 * 面试54：给定一棵二叉搜索树，请找出其中的第K大结点
 * */
const BinaryTreeNode *KthNodeCore(const BinaryTreeNode *pRoot, unsigned int &k) {
	const BinaryTreeNode *target = nullptr;

	if (pRoot->pLeft != nullptr)
		target = KthNodeCore(pRoot->pLeft, k);

	if (target == nullptr) {
		if (k == 1)
			target = pRoot;
		k--;
	}

	if (target == nullptr && pRoot->pRight != nullptr)
		target = KthNodeCore(pRoot->pRight, k);

	return target;
}

const BinaryTreeNode *kthNode(const BinaryTreeNode *pRoot, unsigned int k) {
	if (pRoot == nullptr || k == 0)
		return nullptr;
	return KthNodeCore(pRoot, k);
}

#endif //INTERVIEW_CPP_BINARYTREE_H
