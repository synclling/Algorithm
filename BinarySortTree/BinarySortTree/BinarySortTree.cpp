#include "BinarySortTree.h"


BSTNode* SearchBST(BSTNode* T, int key)
{
	while (T != nullptr)
	{
		if (T->data == key)
			return T;
		else if (T->data > key)
			T = T->lchild;
		else
			T = T->rchild;
	}

	return nullptr;
}


BSTNode* SearchBST_Recursively(BSTNode* T, int key)
{
	if (T == nullptr)
		return nullptr;

	if (T->data == key)
		return T;
	else if (T->data > key)
		return SearchBST_Recursively(T->lchild, key);
	else
		return SearchBST_Recursively(T->rchild, key);
}


int SearchBST(BSTNode* T, int key, BSTNode* &p)
{
	//f指向T的双亲，初始值为NULL
	BSTNode* f = nullptr;

	while (T != nullptr)
	{
		if (T->data == key)
		{
			p = T;
			return TRUE;
		}
		else if (T->data > key)
		{
			f = T;
			T = T->lchild;
		}
		else
		{
			f = T;
			T = T->rchild;
		}
	}

	p = f;
	return FALSE;
}

int SearchBST_Recursively(BSTNode* T, int key, BSTNode* f, BSTNode* &p)
{
	if (T == nullptr)
	{
		p = f;
		return FALSE;
	}

	if (T->data == key)
	{
		p = T;
		return TRUE;
	}
	else if (T->data > key)
	{
		return SearchBST_Recursively(T->lchild, key, T, p);
	}
	else
	{
		return SearchBST_Recursively(T->rchild, key, T, p);
	}
}


int InsertBST(BSTNode* &T, int key)
{
	BSTNode* p = nullptr;

	if (!SearchBST(T, key, p))	//查找不成功
	{
		BSTNode* s = new BSTNode();
		s->data = key;
		s->lchild = s->rchild = nullptr;

		if (p == nullptr)
		{
			T = s;
		}
		else if (p->data > key)
		{
			p->lchild = s;
		}
		else
		{
			p->rchild = s;
		}

		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


int DeleteBST(BSTNode* &T, int key)
{
	if (T == nullptr)
		return FALSE;

	if (T->data == key)
	{
		return Delete(T);
	}
	else if (T->data > key)
	{
		return DeleteBST(T->lchild, key);
	}
	else
	{
		return DeleteBST(T->rchild, key);
	}
}


int Delete(BSTNode* &p)
{
	if (p->lchild == nullptr)	//左子树为空，重新连接右子树
	{
		BSTNode* q = p;
		p = p->rchild;
		delete q;
	}
	else if (p->rchild == nullptr)	//右子树为空，重新连接左子树
	{
		BSTNode* q = p;
		p = p->lchild;
		delete q;
	}
	else//左右子树均不为空
	{
		BSTNode* q = p;
		BSTNode* s = p->lchild;

		while (s->rchild != nullptr)
		{
			q = s;
			s = s->rchild;
		}

		p->data = s->data;

		if (q != p)
		{
			q->rchild = s->lchild;
		}
		else
		{
			q->lchild = s->lchild;
		}

		delete s;
	}

	return TRUE;
}