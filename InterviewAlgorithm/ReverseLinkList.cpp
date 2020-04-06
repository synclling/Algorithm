typedef struct LinkListNode
{
	int data;
	struct LinkListNode *pNext;
} LinkListNode;

// 反转单链表
LinkListNode *ReverseLinkList(LinkListNode *pHead)
{
	LinkListNode *pReverseHead = NULL;
	
	LinkListNode *pPreNode = NULL;
	LinkListNode *pCurNode = pHead;
	while(pCurNode != NULL)
	{
		LinkListNode *pNextNode = pCurNode->pNext;
		
		if(pNextNode == NULL)
			pReverseHead = pCurNode;
		
		pCurNode->pNext = pPreNode;
		
		pPreNode = pCurNode;
		pCurNode = pNextNode;
	}
	
	return pReverseHead;
}

// 合并两个链表
LinkListNode *Merge(LinkListNode *pHead1, LinkListNode *pHead2)
{
	if(pHead1 == NULL)
	{
		return pHead2;
	}
	else if(pHead2 == NULL)
	{
		return pHead1;
	}
	
	LinkListNode *pMergeHead = NULL;
	if(pHead1->data < pHead2->data)
	{
		pMergeHead = pHead1;
		pMergeHead->pNext = Merge(pHead1->pNext, pHead2);
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead->pNext = Merge(pHead1, pHead2->pNext);
	}
	
	return pMergeHead;
}
