typedef struct LinkListNode
{
	int data;
	struct LinkListNode *pNext;
} LinkListNode;

// 时间复杂度O(n)
void RemoveNode(LinkListNode **pHead, int value)
{
	if(pHead == NULL || *pHead == NULL)
	{
		return;
	}
	
	LinkListNode *pToBeDelete = NULL;
	if((*pHead)->data == value)
	{
		pToBeDelete = (*pHead);
		(*pHead) = (*pHead)->pNext;
	}
	else
	{
		LinkListNode *pCurNode = (*pHead);
		while(pCurNode->pNext != NULL && pCurNode->pNext->data != value)
		{
			pCurNode = pCurNode->pNext;
		}
	
		if(pCurNode->pNext != NULL && pCurNode->pNext->data == value)
		{
			pToBeDelete = pCurNode->pNext;
			pCurNode->pNext = pCurNode->pNext->pNext;
		}
	}
	
	if(pToBeDelete != NULL)
	{
		delete pToBeDelete;
		pToBeDelete = NULL;
	}
}

// 时间复杂度O(1)
void RemoveNode(LinkListNode **pHead, LinkListNode *pToBeDelete)
{
	if(pHead == NULL || pToBeDelete == NULL)
	{
		return;
	}
	
	if(pToBeDelete->pNext != NULL)
	{
		LinkListNode *pNextNode = pToBeDelete->pNext;
		pToBeDelete->data = pNextNode->data;
		pToBeDelete->pNext = pNextNode->pNext;
		
		delete pNextNode;
		pNextNode = NULL;
	}
	else if((*pHead) == pToBeDelete)
	{
		delete pToBeDelete;
		pToBeDelete = NULL;
		(*pHead) = NULL;
	}
	else
	{
		LinkListNode *pCurNode = (*pHead);
		while(pCurNode->pNext != pToBeDelete)
		{
			pCurNode = pCurNode->pNext;
		}
		
		pCurNode->pNext = NULL;
		delete pToBeDelete;
		pToBeDelete = NULL;
	}
}
