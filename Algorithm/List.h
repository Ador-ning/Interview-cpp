//
// Created by ning on 2018/5/23.
//

#ifndef INTERVIEW_CPP_LIST_H
#define INTERVIEW_CPP_LIST_H

#include <stdio.h>

struct ListNode {
	int m_nKey;
	ListNode *m_pNext;
};

// 创建 List 结点
ListNode *CreateListNode(int value) {
	ListNode *pNode = new ListNode();
	pNode->m_nKey = value;
	pNode->m_pNext = NULL;

	return pNode;
}

// 连接 List结点
void ConnectListNodes(ListNode *pCurrent, ListNode *pNext) {
	if (pCurrent == NULL) {
		printf("Error to connect two nodes.\n");
		return;
	}

	pCurrent->m_pNext = pNext;
}

// 打印 List 结点
void PrintListNode(ListNode *pNode) {
	if (pNode == NULL)
		printf("The node is NULL.\n");
	else
		printf("The key in node is %d.\n", pNode->m_nKey);
}

// 顺序打印 List
void PrintList(ListNode *pHead) {
	printf("Print List start.\n");

	ListNode *pNode = pHead;

	while (pNode != NULL) {
		printf("%d\t", pNode->m_nKey);
		pNode = pNode->m_pNext;
	}

	printf("\n Print List end.\n");
}

// 销毁 List
void DestroyList(ListNode *pHead) {
	ListNode *pNode = pHead;

	while (pNode != NULL) {
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

// 链表尾部添加 List 结点
void AddToTail(ListNode **pHead, int value) {
	ListNode *pNew = new ListNode();
	pNew->m_nKey = value;
	pNew->m_pNext = NULL;

	if (*pHead != NULL) {
		ListNode *pNode = *pHead;

		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNew;
	} else
		*pHead = pNew;
}

// 删除 List 结点
void RemoveNode(ListNode **pHead, int value) {
	if (pHead == NULL || *pHead == NULL)
		return;

	ListNode *pDeleted = NULL;

	if ((*pHead)->m_nKey == value) { // 删除链表头部
		pDeleted = *pHead;
		(*pHead) = (*pHead)->m_pNext;
	} else {
		ListNode *pNode = *pHead;

		// 移动
		while (pNode->m_pNext != NULL && pNode->m_pNext->m_nKey != value)
			pNode = pNode->m_pNext;

		// 删除
		if (pNode->m_pNext != NULL && pNode->m_pNext->m_nKey == value) {
			pDeleted = pNode->m_pNext;
			pNode->m_pNext = pDeleted->m_pNext;
		}
	}

	if (pDeleted != NULL) {
		delete pDeleted;
		pDeleted = NULL;
	}
}

#endif //INTERVIEW_CPP_LIST_H
