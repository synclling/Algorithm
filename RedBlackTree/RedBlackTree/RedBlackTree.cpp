#include "pch.h"
#include "RedBlackTree.h"

static inline void rbtree_left_rotate(rbtree_node **root, rbtree_node *sentinel, rbtree_node *node);

static inline void rbtree_right_rotate(rbtree_node **root, rbtree_node *sentinel, rbtree_node *node);

void rbtree_init(rbtree *tree, rbtree_node *s, rbtree_insert_pt i)
{
	rbtree_sentinel_init(s);
	tree->root = s;
	tree->sentinel = s;
	tree->insert = i;
}

void rbtree_insert(rbtree *tree, rbtree_node *node)
{

}

void rbtree_delete(rbtree *tree, rbtree_node *node)
{

}



static inline void rbtree_left_rotate(rbtree_node **root, rbtree_node *sentinel, rbtree_node *node)
{
	rbtree_node *temp = node->right;

	node->right = temp->left;

	if (temp->left != sentinel)
	{
		temp->left->parent = node;
	}

	temp->parent = node->parent;
	if (node == *root)
	{
		*root = temp;
	}
	else if (node == node->parent->left)
	{
		node->parent->left = temp;
	}
	else
	{
		node->parent->right = temp;
	}

	temp->left = node;
	node->parent = temp;
}

static inline void rbtree_right_rotate(rbtree_node **root, rbtree_node *sentinel, rbtree_node *node)
{
	rbtree_node *temp = node->left;

	node->left = temp->right;

	if (temp->right != sentinel)
	{
		temp->right->parent = node;
	}

	temp->parent = node->parent;
	if (node == *root)
	{
		*root = temp;
	}
	else if (node == node->parent->left)
	{
		node->parent->left = temp;
	}
	else
	{
		node->parent->right = temp;
	}

	temp->right = node;
	node->parent = temp;
}