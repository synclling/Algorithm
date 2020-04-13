#include "pch.h"
#include "B-Tree.h"

int Search(BTNode* p, KeyType k)
{
	int i = 1;
	for (; i <= p->keynum && k >= p->key[i]; ++i); // 使得i:p->key[i] <= k < p->key[i + 1]
	return i - 1;
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

void InsertBTNode(BTNode* &p, int i, int k, BTNode* q)
{
	int j;
	for (j = p->keynum; j > i; --j)
	{
		p->key[j + 1] = p->key[j];
		p->ptr[j + 1] = p->ptr[j];
	}

	p->key[i + 1] = k;
	p->ptr[i + 1] = q;

	if (q != nullptr)
	{
		q->parent = p;
	}

	++p->keynum;
}

void SplitBTNode(BTNode* &p, BTNode* &q)
{
	int i;
	int s = (m + 1) / 2;
	q = new BTNode();

	q->ptr[0] = p->ptr[s];
	for (i = s + 1; i <= m; ++i)
	{
		q->key[i - s] = p->key[i];
		q->ptr[i - s] = p->ptr[i];
	}

	q->keynum = p->keynum - s;
	q->parent = p->parent;
	for (i = 0; i <= p->keynum - s; ++i)
	{
		if (q->ptr[i] != nullptr)
		{
			q->ptr[i]->parent = q;
		}
	}

	p->keynum = s - 1;
}