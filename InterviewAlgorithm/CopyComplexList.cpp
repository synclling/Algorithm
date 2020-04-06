typedef struct ComplexListNode
{
	int data;
	struct ComplexListNode *pNext;
	struct ComplexListNode *pSibling;
} ComplexListNode;

// 复制节点
void CloneNode(ComplexListNode *pHead)
{
	ComplexListNode *pCurNode = pHead;
	while(pCurNode != NULL)
	{
		ComplexListNode *pCloned = new ComplexListNode();
		pCloned->data = pCurNode->data;
		pCloned->pNext = pCurNode->pNext;
		pCloned->pSibling = NULL;
		
		pCurNode->pNext = pCloned;
		
		pCurNode = pCloned->pNext;
	}
}

// 连接对应的pSibling
void ConnectSiblingNode(ComplexListNode *pHead)
{
	ComplexListNode *pCurNode = pHead;
	while(pCurNode != NULL)
	{
		ComplexListNode *pClonedNode = pCurNode->pNext;
		
		if(pCurNode->pSibling != NULL)
		{
			pClonedNode->pSibling = pCurNode->pSibling->pNext;
		}
		
		pCurNode = pClonedNode->pNext;
	}
}

ComplexListNode *ReconnectNode(ComplexListNode *pHead)
{
	ComplexListNode *pCurNode = pHead;
	
	ComplexListNode *pClonedHead = NULL;
	ComplexListNode *pClonedNode = NULL;
	if(pCurNode != NULL)
	{
		pClonedHead = pCurNode->pNext;
		pClonedNode = pClonedHead;
	}
	
	if(pCurNode != NULL)
	{
		pCurNode->pNext = pClonedNode->pNext;
		pCurNode = pCurNode->pNext;
	}
	while(pCurNode != NULL)
	{
		pClonedNode->pNext = pCurNode->pNext;
		pClonedNode = pClonedNode->pNext;
		
		pCurNode->pNext = pClonedNode->pNext;
		pCurNode = pCurNode->pNext;
	}
	
	return pClonedHead;
}
