#include "pch.h"
#include "B-Tree.h"

int Search(BTNode* p, KeyType k)
{
	int i = 0;
	while (i < p->keynum && k >= p->key[i + 1]) // 使得i:key[i] <= k < key[i + 1]
	{
		++i;
	}
	
	return i;
}

Result SearchBTree(BTNode* T, KeyType k)
{
	Result res;

	BTNode* p = T;
	BTNode* q = nullptr;

	int i = 0;
	bool found = false;

	while (p != nullptr && !found)
	{
		i = Search(p, k);
		if (i > 0 && k == p->key[i])
		{
			found = true;
		}
		else
		{
			q = p;
			p = p->ptr[i];
		}
	}

	if (found)
	{
		res.pt = p;
		res.i = i;
		res.tag = 1;
	}
	else
	{
		res.pt = q;
		res.i = i;
		res.tag = 0;
	}

	return res;
}

void Insert(BTNode* &q, int i, KeyType k, BTNode* ap)
{

}

int InsertBTree(BTNode* &T, KeyType k, BTNode* &q, int i)
{

}