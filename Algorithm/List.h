#include <cstdio>

struct ListNode{
	int m_nKey;
	ListNode *m_pNext;
};

// ���� List ��� 
ListNode *CreateListNode(int value){
	ListNode *pNode = new ListNode();
	pNode->m_nKey = value;
	pNode->m_pNext = NULL;
	
	return pNode; 
}

// ���� List��� 
void ConnectListNodes(ListNode *pCurrent, ListNode *pNext){
	if (pCurrent == NULL){
		printf("Error to connect two nodes.\n");
		return;
	}
	
	pCurrent->m_pNext = pNext;
}

// ��ӡ List ��� 
void PrintListNode(ListNode *pNode){
	if (pNode == NULL)
		printf("The node is NULL.\n");
	else
		printf("The key in node is %d.\n", pNode->m_nKey);
}

// ˳���ӡ List 
void PrintList(ListNode *pHead){
	printf("Print List start.\n");
	
	ListNode *pNode = pHead;
	
	while (pNode != NULL){
		printf("%d\t", pNode->m_nKey);
		pNode = pNode->m_pNext;
	}
	
	printf("\n Print List end.\n");
}

// ���� List 
void DestroyList(ListNode *pHead){
	ListNode *pNode = pHead;
	
	while (pNode != NULL){
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead; 
	} 
}

// ����β����� List ��� 
void AddToTail(ListNode **pHead, int value){
	ListNode *pNew = new ListNode();
	pNew->m_nKey = value;
	pNew->m_pNext = NULL;
	
	if (*pHead != NULL){
		ListNode *pNode = *pHead;
		
		while ( pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		
		pNode->m_pNext = pNew;	
	}
	else
		*pHead = pNew;
}

// ɾ�� List ���
void RemoveNode(ListNode **pHead, int value){
	if (pHead == NULL || *pHead == NULL)
		return;
	
	ListNode *pDeleted = NULL;
	
	if ( (*pHead)->m_nKey == value ){ // ɾ������ͷ�� 
		pDeleted = *pHead;
		(*pHead) = (*pHead)->m_pNext; 
	}
	else
	{
		ListNode *pNode = *pHead;
		
		// �ƶ� 
		while (pNode->m_pNext != NULL && pNode->m_pNext->m_nKey != value)
			pNode = pNode->m_pNext;
		
		// ɾ�� 
		if ( pNode->m_pNext != NULL && pNode->m_pNext->m_nKey == value){
			pDeleted = pNode->m_pNext;
			pNode->m_pNext = pDeleted->m_pNext;
		}
	}
	
	if (pDeleted != NULL){
		delete pDeleted;
		pDeleted = NULL;
	}
} 

















