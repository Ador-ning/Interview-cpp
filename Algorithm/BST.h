//
// Created by ning on 2018/5/27.
//

#ifndef INTERVIEW_CPP_CONVERTBST_H
#define INTERVIEW_CPP_CONVERTBST_H

#include <iostream>
#include "BinaryTree.h"

namespace Algorithm {
// =========================== base operation =========================== //
// BST 中查找
	void BST_search(BinaryTreeNode *pRoot, int x) {

		if (pRoot == nullptr) { // 叶节点
			cout << "Search failed\n";
			return;
		}

		if (x == pRoot->value)
			cout << pRoot->value << endl;
		else if (x < pRoot->value)
			BST_search(pRoot->pLeft, x);
		else
			BST_search(pRoot->pRight, x);
	}

// BST 中插入结点
	void BST_insert(BinaryTreeNode *&pRoot, int x) {
		if (pRoot == nullptr) {
			pRoot = CreateBinaryTreeNode(x);
			return;
		}
		if (x == pRoot->value)
			return;
		else if (x < pRoot->value)
			BST_insert(pRoot->pLeft, x);
		else
			BST_insert(pRoot->pLeft, x);
	}

// 构造 BST
	BinaryTreeNode *CreateBST(int data[], int n) {
		BinaryTreeNode *pRoot = nullptr;

		for (int i = 0; i < n; ++i)
			BST_insert(pRoot, data[i]);
		return pRoot;
	}

// 查找到 BST 中最大权值的结点
	BinaryTreeNode *BST_findMax(BinaryTreeNode *pRoot) {
		while (pRoot->pRight != nullptr)
			pRoot = pRoot->pRight;
		return pRoot;
	}

// 查找到 BST 中最小权值的结点
	BinaryTreeNode *BST_findMin(BinaryTreeNode *pRoot) {
		while (pRoot->pLeft != nullptr)
			pRoot = pRoot->pLeft;
		return pRoot;
	}

// BST 删除结点
	void BST_DeleteNode(BinaryTreeNode *&pRoot, int x) {
		if (pRoot == nullptr)
			return; // base

		if (pRoot->value == x) { // 找到结点

			if (pRoot->pRight == nullptr && pRoot->pLeft == nullptr)
				pRoot = nullptr; // 叶子结点
			else if (pRoot->pLeft != nullptr) { // 左子树不为空
				// 左子树中找最大，顶替 pRoot
				BinaryTreeNode *pre = BST_findMax(pRoot->pLeft); // 找 pRoot 前缀
				pRoot->value = pre->value; // 覆盖
				BST_DeleteNode(pRoot->pLeft, pre->value); // 删除该结点
			} else { // 右子树不为空
				// 左子树中找最小，顶替 pRoot
				BinaryTreeNode *next = BST_findMin(pRoot->pLeft); // 找 pRoot 前缀
				pRoot->value = next->value;
				BST_DeleteNode(pRoot->pRight, next->value);
			}

		} else if (pRoot->value > x)
			BST_DeleteNode(pRoot->pLeft, x);
		else
			BST_DeleteNode(pRoot->pRight, x);

	}


// =========================== Work =========================== //

// 输入一个二叉搜索树，将该 BST 转换成一个排序的双向链接
// 要求：不能创建任何新的结点，只能调整树中的指针
	void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeList) {
		if (pNode == nullptr)
			return;

		BinaryTreeNode *pCurrent = pNode;

		if (pCurrent->pLeft != nullptr)
			ConvertNode(pCurrent->pLeft, pLastNodeList);

		pCurrent->pLeft = *pLastNodeList;

		if (*pLastNodeList != nullptr)
			(*pLastNodeList)->pRight = pCurrent;

		*pLastNodeList = pCurrent;

		if (pCurrent->pRight != nullptr)
			ConvertNode(pCurrent->pRight, pLastNodeList);
	}

	BinaryTreeNode *Convert(BinaryTreeNode *pRoot) {
		BinaryTreeNode *pLastNodeList = nullptr;
		ConvertNode(pRoot, &pLastNodeList);

		// pLastNodeList指向双链表的尾端
		// 需要返回头节点
		BinaryTreeNode *pHeadList = pLastNodeList;
		while (pHeadList != nullptr && pHeadList->pLeft != nullptr) {
			pHeadList = pHeadList->pLeft;
		}
		return pHeadList;
	}


// ======================= 测试 ==============
	void PrintDoubleLinkedList(BinaryTreeNode *pHeadOfList) {
		BinaryTreeNode *pNode = pHeadOfList;

		printf("The nodes from left to right are:\n");
		while (pNode != nullptr) {
			printf("%d\t", pNode->value);

			if (pNode->pRight == nullptr)
				break;
			pNode = pNode->pRight;
		}

		printf("\nThe nodes from right to left are:\n");
		while (pNode != nullptr) {
			printf("%d\t", pNode->value);

			if (pNode->pLeft == nullptr)
				break;
			pNode = pNode->pLeft;
		}

		printf("\n");
	}

	void DestroyList(BinaryTreeNode *pHeadOfList) {
		BinaryTreeNode *pNode = pHeadOfList;
		while (pNode != nullptr) {
			BinaryTreeNode *pNext = pNode->pRight;

			delete pNode;
			pNode = pNext;
		}
	}

	void Test(char *testName, BinaryTreeNode *pRootOfTree) {
		if (testName != nullptr)
			printf("%s begins:\n", testName);

		pre_oder(pRootOfTree);

		BinaryTreeNode *pHeadOfList = Convert(pRootOfTree);

		PrintDoubleLinkedList(pHeadOfList);
	}


	void Test1() {
		BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
		BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
		BinaryTreeNode *pNode14 = CreateBinaryTreeNode(14);
		BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
		BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
		BinaryTreeNode *pNode12 = CreateBinaryTreeNode(12);
		BinaryTreeNode *pNode16 = CreateBinaryTreeNode(16);

		ConnectBinaryNodes(pNode10, pNode6, pNode14);
		ConnectBinaryNodes(pNode6, pNode4, pNode8);
		ConnectBinaryNodes(pNode14, pNode12, pNode16);

		Test("Test1", pNode10);

		DestroyList(pNode4);
	}


	void Test2() {
		BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
		BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
		BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
		BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
		BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);

		ConnectBinaryNodes(pNode5, pNode4, nullptr);
		ConnectBinaryNodes(pNode4, pNode3, nullptr);
		ConnectBinaryNodes(pNode3, pNode2, nullptr);
		ConnectBinaryNodes(pNode2, pNode1, nullptr);

		Test("Test2", pNode5);

		DestroyList(pNode1);
	}


	void Test3() {
		BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
		BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
		BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
		BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
		BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);

		ConnectBinaryNodes(pNode1, nullptr, pNode2);
		ConnectBinaryNodes(pNode2, nullptr, pNode3);
		ConnectBinaryNodes(pNode3, nullptr, pNode4);
		ConnectBinaryNodes(pNode4, nullptr, pNode5);

		Test("Test3", pNode1);

		DestroyList(pNode1);
	}

// 树中只有1个结点
	void Test4() {
		BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
		Test("Test4", pNode1);

		DestroyList(pNode1);
	}

// 树中没有结点
	void Test5() {
		Test("Test5", nullptr);
	}

}
#endif //INTERVIEW_CPP_CONVERTBST_H
