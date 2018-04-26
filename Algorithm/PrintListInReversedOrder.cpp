#include <cstdio>
#include "List.h"
#include <stack>

using namespace std;

// ���� ջ 
void PrintListReversing_Iterative(ListNode *pHead){
	std::stack<ListNode *> nodes;
	
	ListNode *pNode = pHead;
	
	while (pNode != NULL){
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	
	while (!nodes.empty()){
		pNode = nodes.top();
		printf("%d\t", pNode->m_nKey);
		nodes.pop();
	}
}

// �ݹ�
void PrintListReversing_Recursive(ListNode *pHead){
	if (pHead != NULL){
		if (pHead->m_pNext != NULL)
			PrintListReversing_Recursive(pHead->m_pNext);
		
		printf("%d\t", pHead->m_nKey);
	}
} 

// ====================���Դ���====================
void Test(ListNode* pHead)
{
    PrintList(pHead);
    PrintListReversing_Iterative(pHead);
    printf("\n");
    PrintListReversing_Recursive(pHead);
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

// ֻ��һ����������: 1
void Test2()
{
    printf("\nTest2 begins.\n");

    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}

// ������
void Test3()
{
    printf("\nTest3 begins.\n");

    Test(NULL);
}


int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}


