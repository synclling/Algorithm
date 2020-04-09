#pragma once

#define TRUE  1
#define FALSE 0

#define LH +1	// 左高
#define EH  0	// 等高
#define RH -1	// 右高

typedef int ElemType;

typedef struct BinarySortTreeNode
{
	int	bf; // 结点的平衡因子
	ElemType data;
	BinarySortTreeNode*	lchild;
	BinarySortTreeNode* rchild;
} BSTNode;

/*
 *	@brief	对以T为根节点的二叉排序树作左旋转处理
 *	@param	[in/out]T	旋转之后T指向新的根节点
 */
void L_Rotate(BSTNode* &T);

/*
 *	@brief	对以T为根节点的二叉排序树作右旋转处理
 *	@param	[in/out]T	旋转之后T指向新的根节点
 */
void R_Rotate(BSTNode* &T);

/*
 *	@brief	判断在T的左子树插入的新结点的位置，选择平衡类型
 *	@param	[in/out]T	旋转之后T指向新的根节点
 */
void LeftBalance(BSTNode* &T);

/*
 *	@brief	判断在T的右子树插入的新结点的位置，选择平衡类型
 *	@param	[in/out]T	旋转之后T指向新的根节点
 */
void RightBalance(BSTNode* &T);


/*
 *	@brief	若平衡的二叉排序树T中不存在和e相同的结点，则插入一个数据元素为e的新结点。
 *	@param	[in]T		二叉排序树
 *	@param	[in]e		新的数据元素
 *	@param	[in]taller	反映T长高与否
 *	@return 插入成功返回TRUE，否则返回FALSE
 */
int InsertAVL(BSTNode* &T, ElemType e, bool &taller);