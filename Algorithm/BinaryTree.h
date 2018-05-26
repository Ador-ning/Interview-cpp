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

	std::deque<BinaryTreeNode *> dequeTreeNode;
	dequeTreeNode.push_back(pRoot);

	while (dequeTreeNode.size()) {
		BinaryTreeNode *pNode = dequeTreeNode.front();
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

	stream << pRoot->m_nValue << ',';
	Serialize(pRoot->m_pLeft, stream);
	Serialize(pRoot->m_pRight, stream);
}

void Deserialize(BinaryTreeNode **pRoot, istream &stream) {
	int number;
	if (ReadStream(stream, &number)) {
		*pRoot = new BinaryTreeNode();
		(*pRoot)->m_nValue = number;
		(*pRoot)->m_pLeft = nullptr;
		(*pRoot)->m_pRight = nullptr;

		Deserialize(&((*pRoot)->m_pLeft), stream);
		Deserialize(&((*pRoot)->m_pRight), stream);
	}
}

#endif //INTERVIEW_CPP_BINARYTREE_H
