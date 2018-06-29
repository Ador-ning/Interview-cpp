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

#endif //INTERVIEW_CPP_LEET80_H
