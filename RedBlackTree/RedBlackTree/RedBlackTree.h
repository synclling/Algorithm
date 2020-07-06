#pragma once

typedef struct RBTreeNode
{
	int key;
	char data;
	char color;
	struct RBTreeNode *left;
	struct RBTreeNode *right;
	struct RBTreeNode *parent;
} RBTreeNode;

typedef void(*RBTreeInsert)(RBTreeNode *root, RBTreeNode *node, RBTreeNode *sentinel);

typedef struct RBTree
{
	RBTreeNode *root;
	RBTreeNode *sentinel;
	RBTreeInsert insert;
} RBTree;

#define RBTree_Red(node)			((node)->color = 1)
#define RBTree_Black(node)			((node)->color = 0)
#define RBTree_Is_Red(node)			((node)->color)
#define RBTree_Is_Black(node)		(!RBTree_Is_Red(node))
#define RBTree_Sentinel_Init(node)	RBTree_Black(node)	// a sentinel must be black
#define RBTree_Init(tree, s, i)		\
	RBTree_Sentinel_Init(s);		\
	(tree)->root = s;				\
	(tree)->sentinel = s;			\
	(tree)->insert = i;