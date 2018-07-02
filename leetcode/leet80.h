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

	ListNode *pInsert;
	bool ChangeHead = 0;
	bool tag = 0;
	int time = 1;

	if (head->m_nKey < x) {
		pInsert = head;
	} else {
		ListNode tmp(0); // 临时结点
		tmp.m_pNext = head;

		pInsert = &tmp;
		ChangeHead = 1;
		tag = 1;
	}

	ListNode *pMove = head->m_pNext;
	ListNode *pPre = head;

	while (pMove != nullptr) {
		if (pMove->m_nKey < x && tag) {
			pPre->m_pNext = pMove->m_pNext; // 1. 链接后面
			pMove->m_pNext = pInsert->m_pNext; // 2. 插入第一步
			pInsert->m_pNext = pMove; // 3. 插入第二步

			// head = pMove;
			if (ChangeHead == 1 && time == 1) {
				head = pMove;
				time -= 1;
			}

			pMove = pPre->m_pNext;
			pInsert = pInsert->m_pNext;
		} else {
			if (pMove->m_nKey >= x)
				tag = 1;
			pMove = pMove->m_pNext;
			pPre = pPre->m_pNext;
		}
	}
	return head;
}

void test_leet86() {
	ListNode l1(6);
	ListNode l2(4);
	ListNode l3(3);
	ListNode l4(2);
	ListNode l5(5);
	ListNode l6(2);
	ConnectListNodes(&l1, &l2);
	ConnectListNodes(&l2, &l3);
	ConnectListNodes(&l3, &l4);
	ConnectListNodes(&l4, &l5);
	ConnectListNodes(&l5, &l6);

	PrintList(partition(&l1, 3));
}

#endif //INTERVIEW_CPP_LEET80_H
