//
// Created by ning on 2018/5/23.
//

#ifndef INTERVIEW_CPP_LIST_H
#define INTERVIEW_CPP_LIST_H

#include <cstdio>

namespace Algorithm {
	class ListNode {
	public:
		// 构造函数
		ListNode(int x) : m_nKey(x), m_pNext(nullptr) {}

		ListNode() : m_nKey(0), m_pNext(nullptr) {}

	public:
		int m_nKey;
		ListNode *m_pNext;
	};

// 删除有序链表中重复结点
	void DeleteDup(ListNode **pHead) {
		if (pHead == nullptr || *pHead == nullptr)
			return;

		ListNode *pNode = *pHead;
		ListNode *pPreNode = nullptr;

		while (pNode != nullptr) {

			ListNode *pNext = pNode->m_pNext; // 对比是否重复
			bool needDelete = false;

			if (pNext != nullptr && pNext->m_nKey == pNode->m_nKey)
				needDelete = true;

			if (!needDelete) { // 没有遇到重复, 前移
// pPreNode = pNode;
				pNode = pNode->m_pNext;
			} else { // 遇到重复 --> 向前移动直到不重复
				int value = pNode->m_nKey;

				ListNode *pDelete = pNext; // 保留重复值的第一个结点

				while (pDelete->m_nKey ==
				       value && pDelete
				                != nullptr) {
					pNext = pDelete->m_pNext;

					delete
							pDelete;
					pDelete = nullptr;

					pDelete = pNext;
				} // 删除直到 非  value

				pNode->
						m_pNext = pNext;
				pNode = pNext;
			}
		}
	}

// get value and move next
	int getValueAndMoveNext(ListNode *l) {
		int x = 0;
		if (l != nullptr) {
			x = l->m_nKey;
			l = l->m_pNext;
		}
		return x;
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

// 创建 List 结点
	ListNode *CreateListNode(int value) {
		ListNode *pNode = new ListNode();
		pNode->m_nKey = value;
		pNode->m_pNext = NULL;
		return pNode;
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

// 求链表长度 List length
	int ListLength(ListNode *head) {
		if (head == nullptr)
			return 0;
		int i = 0;
		while (head != nullptr) {
			i += 1;
			head = head->m_pNext;
		}
		return i;
	}

// 合并链表(非有序) 有序-升序
	ListNode *mergeTwoLists(ListNode *head1, ListNode *head2) {
		ListNode *p1 = head1;
		ListNode *p2 = head2;

		static ListNode dummy(0); // 做临时头结点
		ListNode *tail = &dummy;

		while (p1 && p2) {
			if (p1->m_nKey < p2->m_nKey) {
				tail->m_pNext = p1;
				p1 = p1->m_pNext;
			} else {
				tail->m_pNext = p2;
				p2 = p2->m_pNext;
			}
			tail = tail->m_pNext;
		}
		if (p1)
			tail->m_pNext = p1;
		if (p2)
			tail->m_pNext = p2;

		return dummy.m_pNext;
	}

// 链表排序 O(n*logn)
	ListNode *sortList(ListNode *head) {
		if (head == nullptr || head->m_pNext == nullptr)
			return head;

		// 找链表中间结点
		ListNode *p1 = head, *p2 = head;
		while (p2 && p2->m_pNext) {
			p1 = p1->m_pNext;
			p2 = p2->m_pNext->m_pNext;
		}

		p2 = p1->m_pNext;
		p1->m_pNext = nullptr; // 分割成两个链表

		// 进行递归
		return mergeTwoLists(sortList(head), sortList(p2));
	}

// 反转链表
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

// 链表结点删除 O(1)  --> 給被删除结点的指针
/*
 * 面试18：给定单向链表的头节点 和 一个结点指针
 * 技巧：将要删除结点的下一个结点信息，复制到该结点。删除其下一个结点空间；注意删除结点的位置
 * */
	void DeleteNode(ListNode **pHead, ListNode *pDeleted) {

		if (!pDeleted || !pHead)
			return;

		// 要删除的结点不是尾结点
		if (pDeleted->m_pNext != nullptr) {
			ListNode *pNext = pDeleted->m_pNext; // 被删除结点的 next
			pDeleted->m_nKey = pNext->m_nKey;
			pDeleted->m_pNext = pNext->m_pNext;
			delete pNext;
			pNext = nullptr;
		} else if (*pHead == pDeleted) { // 链表只有头结点，删除结点也是头结点
			delete pDeleted;
			pDeleted = nullptr;
			*pHead = nullptr;
		} else { // 多个结点链表，要删除结点为 尾结点; 遍历到尾部
			ListNode *pNode = *pHead;

			while (pNode->m_pNext != pDeleted) {
				pNode = pNode->m_pNext;
			}

			pNode->m_pNext = nullptr;
			delete pDeleted;
			pDeleted = nullptr;
		}
	}

// 一个链表中包含环，如何找出环的入口结点？
/*
 * 面试23：
 * */
	ListNode *MeetingNode(ListNode *pHead) {
		if (pHead == nullptr)
			return nullptr;

		ListNode *pSlow = pHead->m_pNext;
		if (pSlow == nullptr)
			return nullptr;

		ListNode *pFast = pSlow->m_pNext;

		while (pFast != nullptr && pSlow != nullptr) {

			if (pFast == pSlow) // 指向
				return pFast;
			pSlow = pSlow->m_pNext;
			pFast = pFast->m_pNext;

			if (pFast != nullptr)
				pFast = pFast->m_pNext;
		}
		return nullptr;
	}

	ListNode *EntryNode(ListNode *pHead) {
		ListNode *meetingNode = MeetingNode(pHead);

		if (meetingNode == nullptr)
			return nullptr;

		// 得到环中结点的数目
		int nodeInLoop = 1;
		ListNode *pNode1 = meetingNode;
		while (pNode1->m_pNext != meetingNode) {
			pNode1 = pNode1->m_pNext;
			++nodeInLoop;
		}

		// 先移动pNode1，次数为环中结点数
		pNode1 = pHead;
		for (int i = 0; i < nodeInLoop; ++i) {
			pNode1 = pNode1->m_pNext;
		}

		// 再移动pNode1和pNode2
		ListNode *pNode2 = pHead;
		while (pNode1 != pNode2) {
			pNode1 = pNode1->m_pNext;
			pNode2 = pNode2->m_pNext;
		}
		return pNode1;
	}

//
}
#endif //INTERVIEW_CPP_LIST_H
