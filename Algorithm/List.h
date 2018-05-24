//
// Created by ning on 2018/5/23.
//

#ifndef INTERVIEW_CPP_LIST_H
#define INTERVIEW_CPP_LIST_H

#include <cstdio>

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

// 反转链表
/*
 * 面试第24题 -- 输入链表头结点，反转该链表并输出
 * */
ListNode *ReverseList(ListNode *pHead) {
	ListNode *pReversedHead = nullptr; // 反转后的头结点指针
	ListNode *pNode = pHead; // 用于指向调整的结点
	ListNode *pPrev = nullptr; // 永远指向反转后的第一个结点
	/*
	 * 原理： 利用辅助指针， 从原链表中一次拆分结点，以头插法加入反转后链表
	 * */

	while (pNode != nullptr) {
		ListNode *pNext = pNode->m_pNext;

		if (pNext == nullptr) // pNode 指向链表尾端
			pReversedHead = pNode;

		pNode->m_pNext = pPrev; // 调整结点，头插
		pPrev = pNode; // 指向下次待头插结点
		pNode = pNext; // 移动到下一个结点
	}

	return pReversedHead;
}

// 链表中倒数第K个结点
/*
 * 面试第22题
 * */
ListNode *FindKthToTail(ListNode *pHead, unsigned int k) {
	if (pHead == nullptr || k == 0)
		return nullptr;

	/*
	 * 技巧：两指针相距 K，然后同时后移
	 * */
	ListNode *pAhead = pHead;
	ListNode *pBehind = nullptr;
	for (unsigned int i = 0; i < k - 1; ++i) {
		if (pAhead->m_pNext != nullptr)
			pAhead = pAhead->m_pNext;
		else // k 大于链表的长度  -- 解决
			return nullptr;
	}
	pBehind = pHead;
	while (pAhead->m_pNext != nullptr) {
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
}

// 合并两个排序的链表
/*
 * 面试题 25
 * */
ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
	if (pHead1 == nullptr)
		return pHead2;
	else if (pHead2 == nullptr)
		return pHead1;

	ListNode *pMergedHead = nullptr;

	if (pHead1->m_nKey < pHead2->m_nKey) {
		pMergedHead = pHead1;
		pMergedHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
	} else {
		pMergedHead = pHead2;
		pMergedHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
	}
	return pMergedHead;
}




#endif //INTERVIEW_CPP_LIST_H
