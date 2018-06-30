//
// Created by ning on 2018/6/29.
//

#ifndef INTERVIEW_CPP_LEET80_H
#define INTERVIEW_CPP_LEET80_H


// ============================== 题目83 删除链表中重复元素
ListNode *deleteDuplicates(ListNode *head) {

	if (head == nullptr)
		return head;
	ListNode *p = head;
	ListNode *pDelete = head->m_pNext;

	while (pDelete->m_pNext != nullptr) {
		if (p->m_nKey == pDelete->m_nKey) {
			p->m_pNext = pDelete->m_pNext;
		} else {
			p = p->m_pNext;
		}
		pDelete = pDelete->m_pNext;
	}
	return head;
}

// ============================== 题目86 分割链表
ListNode *partition(ListNode *head, int x) {
	if (head == nullptr)
		return head;

	// 头插法
	ListNode *pMove = head->m_pNext;
	ListNode *pPre = head;

	while (pMove != nullptr) {
		if (pMove->m_nKey < x) {
			pPre->m_pNext = pMove->m_pNext; // 移动
			pMove->m_pNext = head;
			head = pMove;
		}
		pMove = pMove->m_pNext;
		pPre = pPre->m_pNext;
	}
	return head;
}

#endif //INTERVIEW_CPP_LEET80_H
