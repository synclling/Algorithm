#include "pch.h"
#include "B-Tree.h"

int Search(BTNode* p, KeyType k)
{
	int i = 0;
	while (i < p->keynum && k >= p->key[i + 1])
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
		i = Search(p, k); // 使得i:key[i] <= k < key[i + 1]
		if (i > 0 && p->key[i] == k)
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

void Insert(BTNode* q, int i, KeyType k, BTNode* ap)
{
	for (int j = q->keynum; j > i; --j) // i后面的元素往后移一个元素
	{
		q->key[j + 1] = q->key[j];
		q->ptr[j + 1] = q->ptr[j];
	}

	q->key[i + 1] = k;
	q->ptr[i + 1] = ap;

	if (ap != nullptr)
	{
		ap->parent = q;
	}
	
	++q->keynum;
}

void Split(BTNode* q, int s, BTNode* &ap)
{
	int i, j;
	ap = new BTNode();

	ap->ptr[0] = q->ptr[s];
	for (i = s + 1, j = 1; i < q->keynum; ++i, ++j)
	{
		ap->key[j] = q->key[i];
		ap->ptr[j] = q->ptr[i];
	}
	ap->keynum = q->keynum - s;
	ap->parent = q->parent;


	for (i = 0; i <= q->keynum - s; ++i) // 更新子结点的父域指针
	{
		if (ap->ptr[i] != nullptr)
		{
			ap->ptr[i]->parent = ap;
		}
	}

	q->keynum = s - 1;
}

void NewRoot(BTNode* &T, BTNode* q, KeyType x, BTNode* ap)
{
	T = new BTNode();
	T->keynum = 1;
	T->key[1] = x;
	T->ptr[0] = q;
	T->ptr[1] = ap;

	if (q != nullptr)
	{
		q->parent = T;
	}

	if (ap != nullptr)
	{
		ap->parent = T;
	}

	T->parent = nullptr;
}

int InsertBTree(BTNode* &T, KeyType k, BTNode* q, int i)
{
	KeyType x = k;
	BTNode* ap = nullptr;
	bool finished = false;

	while (q != nullptr && !finished)
	{
		Insert(q, i, x, ap); // 将x和ap分别插入到q->key[i + 1]和q->ptr[i + 1]
		if (q->keynum < m)
		{
			finished = true; // 插入完成
		}
		else
		{
			int s = (m + 1) / 2; // 向上取整[m/2]
			Split(q, s, ap); // 将q->key[s + 1...m], q->ptr[s...m]插入到新结点ap
			
			x = q->key[s];
			if (q->parent != nullptr)
			{
				q = q->parent;
				i = Search(q, x);
			}
		}
	}

	if (!finished)
	{
		NewRoot(T, q, x, ap);
	}

	return 1;
}

void Successor(BTNode* &p, int i)
{
	BTNode* child = p->ptr[i];
	while (child->ptr[0] != nullptr)
	{
		child = child->ptr[0];
	}

	p->key[i] = child->key[1];
	
	p = child;
}

void Remove(BTNode* &p, int i)
{
	for (int j = i; j < p->keynum; ++j)
	{
		p->key[j] = p->key[j + 1];
		p->ptr[j] = p->ptr[j + 1];
	}

	--p->keynum;
}

void DeleteBTNode(BTNode* &T, BTNode* p, int i)
{
	if (p->ptr[i] != nullptr) // 待删除关键字所在的结点为非终端结点
	{
		Successor(p, i);
		DeleteBTNode(T, p, 1);
	}
	else // 待删除关键字所在的结点为终端结点
	{
		Remove(p, i);
		//if (p->keynum < (m - 1) / 2) // 删除后关键字数目少于
		//{
		//}
	}
}

int DeleteBTree(BTNode* &T, KeyType k)
{
	Result res = SearchBTree(T, k);
	if (res.tag == 0) // 查找失败
	{
		return 0;
	}
	DeleteBTNode(T, res.pt, res.i);
	return 1;
}