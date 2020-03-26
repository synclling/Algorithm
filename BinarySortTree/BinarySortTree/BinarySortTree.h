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
 *	@brief	�ڶ���������T�в��ҹؼ��ֵ���key�Ľ��
 *	@param	[in]T		����������
 *	@param	[in]key		�ؼ���key
 *	@return ���ҳɹ����ظý�㣬ʧ�ܷ���NULL
 */
BSTNode* SearchBST(BSTNode* T, int key);
BSTNode* SearchBST_Recursively(BSTNode* T, int key);


/*
 *	@brief	�ڶ���������T�в��ҹؼ��ֵ���key�Ľ��
 *	@param	[in]T		����������
 *	@param	[in]key		�ؼ���key
 *	@param	[out]p		���ҳɹ�pָ��ý��;����ʧ��p�����·���Ϸ��ʵ����һ�����
 *	@return ���ҳɹ�����TRUE��ʧ�ܷ���FALSE
 */
int SearchBST(BSTNode* T, int key, BSTNode* &p);
int SearchBST_Recursively(BSTNode* T, int key, BSTNode* f, BSTNode* &p);


/*
 *	@brief	�ڶ���������T(�����ڹؼ��ֵ���key�Ľ��)�в���ؼ��ֵ���key�Ľ��
 *	@param	[in]T		����������
 *	@param	[in]key		�ؼ���key
 *	@return ����ɹ�����TRUE��ʧ�ܷ���FALSE
 */
int InsertBST(BSTNode* &T, int key);


/*
 *	@brief	�ڶ���������T(���ڹؼ��ֵ���key�Ľ��)��ɾ���ؼ��ֵ���key�Ľ��
 *	@param	[in]T		����������
 *	@param	[in]key		�ؼ���key
 *	@return ɾ���ɹ�����TRUE��ʧ�ܷ���FALSE
 */
int DeleteBST(BSTNode* &T, int key);


/*
 *	@brief	�ڶ���������T��ɾ�����p������������������������������
 *	@param	[in]p		��ɾ�����
 *	@return ɾ���ɹ�����TRUE
 */
int Delete(BSTNode* &p);