typedef struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *pLeftNode;
	struct BinaryTreeNode *pRightNode;
} BinaryTreeNode;


void MirrorRecursively(BinaryTreeNode *pRoot)
{
	if(pRoot == NULL || (pRoot->pLeftNode == NULL && pRoot->pRightNode == NULL))
	{
		return;
	}
	
	BinaryTreeNode *pTemp = pRoot->pLeftNode;
	pRoot->pLeftNode = pRoot->pRightNode;
	pRoot->pRightNode = pTemp;
	
	if(pRoot->pLeftNode != NULL)
	{
		MirrorRecursively(pRoot->pLeftNode);
	}
	
	if(pRoot->pRightNode != NULL)
	{
		MirrorRecursively(pRoot->pRightNode);
	}
}
