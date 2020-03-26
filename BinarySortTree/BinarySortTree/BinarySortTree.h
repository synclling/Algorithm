#pragma once
#include "pch.h"

#define TRUE	1
#define FALSE	0

typedef struct BinarySortTreeNode
{
	int data;
	struct BinarySortTreeNode* lchild;
	struct BinarySortTreeNode* rchild;
} BSTNode;


/*
 *	@brief	在二叉排序树T中查找关键字等于key的结点
 *	@param	[in]T		二叉排序树
 *	@param	[in]key		关键字key
 *	@return 查找成功返回该结点，失败返回NULL
 */
BSTNode* SearchBST(BSTNode* T, int key);
BSTNode* SearchBST_Recursively(BSTNode* T, int key);


/*
 *	@brief	在二叉排序树T中查找关键字等于key的结点
 *	@param	[in]T		二叉排序树
 *	@param	[in]key		关键字key
 *	@param	[out]p		查找成功p指向该结点;查找失败p向查找路径上访问的最后一个结点
 *	@return 查找成功返回TRUE，失败返回FALSE
 */
int SearchBST(BSTNode* T, int key, BSTNode* &p);
int SearchBST_Recursively(BSTNode* T, int key, BSTNode* f, BSTNode* &p);


/*
 *	@brief	在二叉排序树T(不存在关键字等于key的结点)中插入关键字等于key的结点
 *	@param	[in]T		二叉排序树
 *	@param	[in]key		关键字key
 *	@return 插入成功返回TRUE，失败返回FALSE
 */
int InsertBST(BSTNode* &T, int key);


/*
 *	@brief	在二叉排序树T(存在关键字等于key的结点)中删除关键字等于key的结点
 *	@param	[in]T		二叉排序树
 *	@param	[in]key		关键字key
 *	@return 删除成功返回TRUE，失败返回FALSE
 */
int DeleteBST(BSTNode* &T, int key);


/*
 *	@brief	在二叉排序树T中删除结点p，并重新连接它的左子树或右子树
 *	@param	[in]p		待删除结点
 *	@return 删除成功返回TRUE
 */
int Delete(BSTNode* &p);