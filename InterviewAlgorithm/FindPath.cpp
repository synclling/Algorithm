typedef struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode* pLeft;
	struct BinaryTreeNode* pRight;
} BinaryTreeNode;

void FindPath(BinaryTreeNode* pRoot, std::vector<int> &path, int expectSum, int &currentSum)
{
	currentSum += pRoot->data;
	path.push_back(pRoot->data);
	
	bool isLeaf = (pRoot->pLeft == NULL && pRoot->pRight == NULL)
	if(currentSum == expectSum && isLeaf)
	{
		printf("A path is found: ");
		std::vector<int>::iterator it = path.begin();
		for(; it != path.end(); ++it)
			printf("%d\t", *it);
		printf("\n");
	}
	
	if(pRoot->pLeft != NULL)
	{
		FindPath(pRoot->pLeft, path, expectSum, currentSum);
	}
	
	if(pRoot->pRight != NULL)
	{
		FindPath(pRoot->pRight, path, expectSum, currentSum);
	}
	
	currentSum -= pRoot->data;
	path.pop_back();
}

void FindPath(BinaryTreeNode* pRoot, int expectSum)
{
	if(pRoot == NULL)
		return;
	
	std::vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, path, expectSum, currentSum);
}
