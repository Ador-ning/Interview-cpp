//
// Created by ning on 2018/8/13.
//

#ifndef INTERVIEW_CPP_DFS_H
#define INTERVIEW_CPP_DFS_H

#include <iostream>
#include <vector>
#include "../Algorithm/List.h"
#include "../Algorithm/BinaryTree.h"

using namespace std;

namespace Algorithm {
// convert sorted list to binary tree
	BinaryTreeNode *sortedListToBST(int low, int high, ListNode *&head) {
		if (low > high || head == nullptr)
			return nullptr;
		int mid = low + (high - low) / 2;

		BinaryTreeNode *leftNode = sortedListToBST(low, mid - 1, head); // 左

		BinaryTreeNode *node = new BinaryTreeNode(head->m_nKey); // 中
		node->pLeft = leftNode;
		head = head->m_pNext;

		BinaryTreeNode *rightNode = sortedListToBST(mid + 1, high, head); // 右
		node->pRight = rightNode;

		return node;
	}

	BinaryTreeNode *sortedListToBST(ListNode *head) {
		int len = 0;
		for (ListNode *p = head; p != nullptr; p = p->m_pNext)
			len++;

		return sortedListToBST(0, len - 1, head);
	}
}
#endif //INTERVIEW_CPP_DFS_H
