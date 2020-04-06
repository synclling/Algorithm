typedef struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *pLeft;
	struct BinaryTreeNode *pRight;
} BinaryTreeNode;

void ConvertNodeRecursively(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList)
{
	if(pNode == NULL)
	{
		return;
	}
	
	BinaryTreeNode *pCurrentNode = pNode;
	
	if(pCurrentNode->pLeft != NULL)
	{
		ConvertNode(pCurrentNode->pLeft, pLastNodeInList);
	}
	
	pCurrentNode->pLeft = *pLastNodeInList;
	if((*pLastNodeInList) != NULL)
	{
		(*pLastNodeInList)->pRight = pCurrentNode;
	}
	
	pLastNodeInList = pCurrentNode;
	
	if(pCurrentNode->pRight != NULL)
	{
		ConvertNode(pCurrentNode->pRight, pLastNodeInList);
	}
}

void ConvertNode(BinaryTreeNode *pNode)
{
	if(pNode == NULL)
	{
		return;
	}
	
	BinaryTreeNode *pCurrentNode = pNode;
	BinaryTreeNode *pLastNodeInList = NULL;
	
	std::stack<BinaryTreeNode*> S;
	while(!S.empty() || pCurrentNode != NULL)
	{
		while(pCurrentNode != NULL)
		{
			S.push(pCurrentNode);
			pCurrentNode = pCurrentNode->pLeft;
		}
		
		if(!S.empty())
		{
			pCurrentNode = S.top();
			S.pop();
			
			pCurrentNode->pLeft = pLastNodeInList;
			if(pLastNodeInList != NULL)
			{
				pLastNodeInList->pRight = pCurrentNode;
			}
			
			pLastNodeInList = pCurrentNode;
			
			pCurrentNode = pCurrentNode->pRight;
		}
	}
}

BinaryTreeNode *Convert(BinaryTreeNode *pRoot)
{
	
}
