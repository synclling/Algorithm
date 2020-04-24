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
			int s = (m + 1) / 2; // 向上取整⌈m / 2⌉
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


void Remove(BTNode* &p, int i)
{
	for (int j = i; j < p->keynum; ++j)
	{
		p->key[j] = p->key[j + 1];
		p->ptr[j] = p->ptr[j + 1];
	}

	--p->keynum;
}

void Restore(BTNode* &T, BTNode* p, int i)
{
	BTNode* ap = p->parent;
	if (ap == nullptr)
	{
		delete p;
		T = nullptr;
		return;
	}

	BTNode* lc = nullptr;
	BTNode* rc = nullptr;
	bool finished = false;
	while (!finished)
	{
		int r = 0;
		while (ap->ptr[r] != p) ++r;
		if (r == 0)
		{
			lc = nullptr;
			rc = ap->ptr[r + 1];
		}
		else if (r == ap->keynum)
		{
			lc = ap->ptr[r - 1];
			rc = nullptr;
		}
		else
		{
			lc = ap->ptr[r - 1];
			rc = ap->ptr[r + 1];
		}

		if (r > 0 && lc != nullptr && lc->keynum > ((m - 1) / 2)) // 向左兄弟借关键字
		{
			for (int j = p->keynum; j >= 1; --j) // 关键字和指针向量向后移动
			{
				p->key[j + 1] = p->key[j];
				p->ptr[j + 1] = p->ptr[j];
			}
			p->ptr[1] = p->ptr[0]; // A0指针移动A1位置
			
			p->key[1] = ap->key[r]; // 双亲结点的关键字移到p
			p->ptr[0] = lc->ptr[lc->keynum];
			if (p->ptr[0] != nullptr)
			{
				p->ptr[0]->parent = p; // 更新p的孩子结点的父域指针
			}

			ap->key[r] = lc->key[lc->keynum]; // 左兄弟的关键字上移到双亲结点

			++p->keynum;
			--lc->keynum;

			finished = true;
			break;
		}
		else if (r < ap->keynum && rc != nullptr && rc->keynum >((m - 1) / 2)) // 向右兄弟借关键字
		{
			p->key[p->keynum + 1] = ap->key[r + 1];
			p->ptr[p->keynum + 1] = rc->ptr[0];
			if (p->ptr[p->keynum + 1] != nullptr)
			{
				p->ptr[p->keynum + 1]->parent = p;
			}

			ap->key[r + 1] = rc->key[1];

			rc->ptr[0] = rc->ptr[1];
			for (int j = 1; j < rc->keynum; ++j)
			{
				rc->key[j] = rc->key[j + 1];
				rc->ptr[j] = rc->ptr[j + 1];
			}

			++p->keynum;
			--rc->keynum;

			finished = true;
			break;
		}
		else if (r > 0 && lc != nullptr && lc->keynum <= ((m - 1) / 2)) // 左兄弟关键字不足借，向左兄弟靠拢合并
		{
			for (int j = p->keynum; j >= 1; --j) // 关键字和指针向量向后移动
			{
				p->key[j + 1] = p->key[j];
				p->ptr[j + 1] = p->ptr[j];
			}
			p->ptr[1] = p->ptr[0]; // A0指针移动A1位置

			p->key[1] = ap->key[r]; // 合并双亲结点的关键字
			++p->keynum;

			for (int j = 1; j <= p->keynum; ++j) // 更新p的孩子结点的父域指针
			{
				if (p->ptr[j] != nullptr)
				{
					p->ptr[j]->parent = lc;
				}
			}

			for (int j = 1; j <= p->keynum; ++j) // 将p结点的关键字合并到左兄弟
			{
				lc->key[lc->keynum + j] = p->key[j];
				lc->ptr[lc->keynum + j] = p->ptr[j];
			}
			lc->keynum += p->keynum;

			for (int j = r; j < ap->keynum; ++j) // 双亲结点关键字与指针向左移动一位
			{
				ap->key[j] = ap->key[j + 1];
				ap->ptr[j] = ap->ptr[j + 1];
			}
			ap->ptr[0] = lc; // 重新指向lc
			--ap->keynum;

			delete p; // 删除p结点
			p = lc;
		}
		else if (r < ap->keynum && rc != nullptr && rc->keynum <= ((m - 1) / 2)) // 右兄弟关键字不足借，向右兄弟靠拢合并
		{
			p->key[p->keynum + 1] = ap->key[r + 1]; // 合并双亲结点的关键字
			p->ptr[p->keynum + 1] = rc->ptr[0];
			++p->keynum;

			for (int j = 1; j <= rc->keynum; ++j) // 右兄弟结点的关键字与指针向后移动p->keynum个位置
			{
				rc->key[p->keynum + j] = rc->key[j];
				rc->ptr[p->keynum + j] = rc->ptr[j];
			}

			for (int j = 1; j <= p->keynum; ++j) // 将p结点的关键字与指针移到右兄弟
			{
				rc->key[j] = p->key[j];
				rc->ptr[j] = p->ptr[j];
			}
			rc->ptr[0] = p->ptr[0];
			rc->keynum += p->keynum;

			for (int j = 0; j <= rc->keynum; ++j)
			{
				if (rc->ptr[j] != nullptr)
				{
					rc->ptr[j]->parent = rc;
				}
			}

			for (int j = r + 1; j < ap->keynum; ++j)
			{
				ap->key[j] = ap->key[j + 1];
				ap->ptr[j] = ap->ptr[j + 1];
			}
			ap->ptr[r] = rc;
			--ap->keynum;

			delete p;
			p = rc;
		}


		if (ap->keynum >= ((m - 1) / 2) || (ap->parent == nullptr && ap->keynum > 0))
		{
			finished = true;
		}
		else if (ap->parent == nullptr && ap->keynum <= 0) // 出现空的根结点
		{
			T = p; // 根结点下移
			delete ap;
			ap = nullptr;

			finished = true;
			break;
		}

		ap = ap->parent;
		p = p->parent;
	}
}

void DeleteBTNode(BTNode* &T, BTNode* p, int i)
{
	if (p->ptr[i] != nullptr) // 待删除关键字所在的结点为非终端结点
	{
		BTNode* child = p->ptr[i];
		while (child->ptr[0] != nullptr)
		{
			child = child->ptr[0];
		}
		p->key[i] = child->key[1];

		DeleteBTNode(T, child, 1);
	}
	else // 待删除关键字所在的结点为最下面一层的非终端结点
	{
		Remove(p, i);
		// B-Tree的关键字临界点为⌈m / 2⌉ - 1，等价于(m - 1) / 2
		if (p->keynum >= ((m - 1) / 2))
		{
			// 删除之后大于等于临界点，无须操作
		}
		else if (p->keynum < ((m - 1) / 2)) // 删除之后关键字数目少于临界点
		{
			Restore(T, p, i);
		}
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