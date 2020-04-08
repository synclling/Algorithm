#include "pch.h"
#include "BalancedBinaryTree.h"

void L_Rotate(BSTNode* &root)
{
	BSTNode* p = root->rchild;
	root->rchild = p->lchild;
	p->lchild = root;

	root = p;
}

void R_Rotate(BSTNode* &root)
{
	BSTNode* p = root->lchild;
	root->lchild = p->rchild;
	p->rchild = root;

	root = p;
}

int InsertAVL(BSTNode* &T, ElemType e, bool &taller)
{
	if (T == nullptr)
	{
		// 插入新结点，树"长高"，置taller为true
		T = new BSTNode();
		T->bf = EH;
		T->data = e;
		T->lchild = T->rchild = nullptr;
		taller = true;
	}
	else
	{
		if (T->data == e)	// 树中已存在和e相同的结点
		{
			taller = false;
			return FALSE;
		}
		else if(T->data > e) // 在T的左子树中搜索
		{
			if (!InsertAVL(T->lchild, e, taller))
			{
				return FALSE;
			}

			if (taller)
			{
				switch (T->bf)
				{
				case LH:
				{

				}
				break;
				case EH:
				{
					T->bf = LH;
					taller = true;
				}
				break;
				case RH:
				{
					T->bf = EH;
					taller = false;
				}
				break;
				}
			}
		}
		else
		{
			if (!InsertAVL(T->rchild, e, taller))
			{
				return FALSE;
			}

			if (taller)
			{
				switch (T->bf)
				{
				case LH:
				{
					T->bf = EH;
					taller = false;
				}
				break;
				case EH:
				{
					T->bf = RH;
					taller = true;
				}
				break;
				case RH:
				{

				}
				break;
				}
			}
		}
	}

	return true;
}