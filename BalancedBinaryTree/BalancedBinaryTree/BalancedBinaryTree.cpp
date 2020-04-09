#include "pch.h"
#include "BalancedBinaryTree.h"

void L_Rotate(BSTNode* &T)
{
	BSTNode* p = T->rchild;
	T->rchild = p->lchild;
	p->lchild = T;

	T = p;
}

void R_Rotate(BSTNode* &T)
{
	BSTNode* p = T->lchild;
	T->lchild = p->rchild;
	p->rchild = T;

	T = p;
}

void LeftBalance(BSTNode* &T)
{
	BSTNode* lc = T->lchild; // lc指向T的左子树
	switch (lc->bf)
	{
	case LH: // 新结点插入在T的左孩子的左孩子上，作单右旋转处理
	{
		T->bf = lc->bf = EH;
		L_Rotate(T);
	}
	break;
	case RH: // 新结点插入在T的左子树的右孩子上，作先左后右双旋转处理
	{
		BSTNode* rd = lc->rchild;
		switch (rd->bf) // 判断rd的平衡因子，决定了T和lc的平衡因子
		{
		case LH:
		{
			T->bf = RH;
			lc->bf = EH;
		}
		break;
		case EH:
		{
			T->bf = EH;
			lc->bf = EH;
		}
		break;
		case RH:
		{
			T->bf = EH;
			lc->bf = LH;
		}
		break;
		}
		rd->bf = EH;
		L_Rotate(T->lchild);
		R_Rotate(T);
	}
	break;
	}
}

void RightBalance(BSTNode* &T)
{
	BSTNode* rc = T->rchild;
	switch (rc->bf)
	{
	case LH: // 新结点插入在T的右孩子的左孩子上，作先右后左的双旋转处理
	{
		BSTNode* rd = rc->lchild;
		switch (rd->bf) // 判断rd的平衡因子，决定了T和lc的平衡因子
		{
		case LH:
		{
			T->bf = EH;
			rc->bf = RH;
		}
		break;
		case EH:
		{
			T->bf = EH;
			rc->bf = EH;
		}
		break;
		case RH:
		{
			T->bf = LH;
			rc->bf = EH;
		}
		break;
		}

		rd->bf = EH;
		R_Rotate(T->rchild);
		L_Rotate(T);
	}
	break;
	case RH: // 新结点插入在T的右孩子的右孩子上，作单向左旋转处理
	{
		T->bf = rc->bf = EH;
		L_Rotate(T);
	}
	break;
	}
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
					LeftBalance(T);
					taller = false;
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
					RightBalance(T);
					taller = false;
				}
				break;
				}
			}
		}
	}

	return true;
}