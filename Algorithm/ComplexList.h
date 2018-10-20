//
// Created by ning on 2018/5/27.
//

#ifndef INTERVIEW_CPP_COMPLEXLIST_H
#define INTERVIEW_CPP_COMPLEXLIST_H

#include <iostream>

namespace Algorithm {
	struct ComplexListNode {
		int value;
		ComplexListNode *pNext;
		ComplexListNode *pSibling; // 指向任意结点或者nullptr
	};

	ComplexListNode *CreateNode(int value) {
		ComplexListNode *pNode = new ComplexListNode();

		pNode->value = value;
		pNode->pNext = nullptr;
		pNode->pSibling = nullptr;
	}

	void BuildNodes(ComplexListNode *pNode, ComplexListNode *pNext, ComplexListNode *pSibling) {
		if (pNode != nullptr) {
			pNode->pSibling = pSibling;
			pNode->pNext = pNext;
		}
	}

	void PrintList(ComplexListNode *pHead) {

		ComplexListNode *pNode = pHead;

		while (pNode != nullptr) {
			std::cout << "The value of this Node is : %d" << pNode->value << endl;

			if (pNode->pSibling == nullptr)
				std::cout << "This node does not have sibling." << endl;
			else
				std::cout << "The value of its sibling is : %d" << pNode->pSibling->value << endl;

			std::cout << endl;
			pNode = pNode->pNext;
		}
	}

// 辅助链表的复制
/*
 * 面试35
 */
	void CloneNodes(ComplexListNode *pHead) {
		ComplexListNode *pNode = pHead;

		while (pNode != nullptr) {
			ComplexListNode *pCloned = new ComplexListNode();
			pCloned->value = pNode->value;
			pCloned->pNext = pNode->pNext;
			pCloned->pSibling = nullptr;

			pNode->pNext = pCloned;
			pNode = pCloned->pNext;
		}
	}

	void ConnectSiblingNodes(ComplexListNode *pHead) {
		ComplexListNode *pNode = pHead;

		while (pNode != nullptr) {
			ComplexListNode *pCloned = pNode->pNext;
			if (pNode->pSibling != nullptr)
				pCloned->pSibling = pNode->pSibling;

			pNode = pCloned->pNext;
		}
	}

	ComplexListNode *ReconnectNodes(ComplexListNode *pHead) {
		ComplexListNode *pNode = pHead;
		ComplexListNode *pCloneHead = nullptr;
		ComplexListNode *pClonedNode = nullptr;

		if (pNode != nullptr) {
			pCloneHead = pClonedNode = pNode->pNext;
			pNode->pNext = pClonedNode->pNext;
			pNode = pNode->pNext;
		}

		while (pNode != nullptr) {
			pClonedNode->pNext = pNode->pNext;
			pClonedNode = pClonedNode->pNext;

			pNode->pNext = pClonedNode->pNext;
			pNode = pNode->pNext;
		}
		return pCloneHead;
	}

	ComplexListNode *Clone(ComplexListNode *pHead) {
		CloneNodes(pHead);
		ConnectSiblingNodes(pHead);
		return ReconnectNodes(pHead);
	}

}
#endif //INTERVIEW_CPP_COMPLEXLIST_H
