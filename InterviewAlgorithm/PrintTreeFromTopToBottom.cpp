typedef struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode* pLeft;
	struct BinaryTreeNode* pRight;
} BinaryTreeNode;

void PrintFromTopToBottom(BinaryTreeNode *pRoot)
{
	if(pRoot == NULL)
	{
		return;
	}
	
	std::deque<BinaryTreeNode*> dequeTreeNode;
	dequeTreeNode.push_back(pRoot);
	
	while(dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		
		printf("%d ", pNode->data);
		
		if(pNode->pLeft != NULL)
		{
			dequeTreeNode.push_back(pNode->pLeft);
		}
		
		if(pNode->pRight != NULL)
		{
			dequeTreeNode.push_back(pNode->pRight);
		}
	}
	
}