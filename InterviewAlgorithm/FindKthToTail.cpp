typedef struct LinkListNode
{
	int data;
	struct LinkListNode *pNext;
} LinkListNode;

LinkListNode *FindKthToTail(LinkListNode *pHead, unsigned int k)
{
	if(pHead == NULL || k == 0)
	{
		return NULL;
	}
	
	LinkListNode *pAhead = pHead;
	LinkListNode *pBehind = pHead;
	
	for(unsigned int i = 1; i < k; ++i)
	{
		if(pAhead->pNext != NULL)
		{
			pAhead = pAhead->pNext;
		}
		else
		{
			return NULL;
		}
	}
	
	while(pAhead->pNext != NULL)
	{
		pAhead = pAhead->pNext;
		pBehind = pBehind->pNext;
	}
	
	return pBehind;
}
