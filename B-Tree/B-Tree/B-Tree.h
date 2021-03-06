﻿#pragma once

#define m 3	// B-树的阶

typedef int KeyType;	// 关键字类型

typedef struct BTreeNode
{
	int keynum;				// 结点中关键字个数
	BTreeNode* parent;		// 指向双亲结点
	KeyType key[m + 1];		// 关键字向量，0号单元不使用
	BTreeNode* ptr[m + 1];	// 子树指针向量
} BTNode;

typedef struct Result
{
	BTreeNode* pt;			// 指向找到的结点
	int i;					// 关键字在结点中的位置
	int tag;				// 1:查找成功，0:查找失败
} Result;

/*
 *	@brief	在m阶的B-树T上查找关键字k，返回结果(pt, i, tag)
 *	@param	[in]T		B-树
 *	@param	[in]k		关键字k
 *	@return 查找成功tag = 1，指针pt所指结点中的第i个关键字等于k；否则tag = 0
 */
Result SearchBTree(BTNode* T, KeyType k);

/*
 *	@brief	在m阶的B-树T上的q结点的key[i]和key[i + 1]之间插入关键字k
 *	@param	[in]T		B-树
 *	@param	[in]k		关键字k
 *	@param	[in]q		结点q
 *	@param	[in]i		关键字位置i
 *	@return 插入成功返回1
 */
int InsertBTree(BTNode* &T, KeyType k, BTNode* q, int i);

/*
 *	@brief	在m阶的B-树T上删除关键字k
 *	@param	[in]T		B-树
 *	@param	[in]k		关键字k
 *	@return 删除成功返回1，失败返回0
 */
int DeleteBTree(BTNode* &T, KeyType k);