﻿#include "pch.h"
#include "RedBlackTree.h"

static inline void rbtree_left_rotate(rbtree_node **root, rbtree_node *sentinel, rbtree_node *node);

static inline void rbtree_right_rotate(rbtree_node **root, rbtree_node *sentinel, rbtree_node *node);

static inline rbtree_node *rbtree_min(rbtree_node *node, rbtree_node *sentinel);

void rbtree_init(rbtree *tree, rbtree_node *s, rbtree_insert_pt i)
{
	rbtree_sentinel_init(s);
	tree->root = s;
	tree->sentinel = s;
	tree->insert = i;
}

void rbtree_insert(rbtree *tree, rbtree_node *node)
{
	rbtree_node *temp = NULL;

	rbtree_node **root = &(tree->root);
	rbtree_node *sentinel = tree->sentinel;

	if (*root == sentinel)	// 根结点为空
	{
		node->parent = NULL;
		node->left = sentinel;
		node->right = sentinel;
		rbt_black(node);	// 根结点必须为黑色
		*root = node;

		return;
	}

	tree->insert(*root, node, sentinel);	// 插入结点

	while (node != *root && rbt_is_red(node->parent))
	{
		if (node->parent == node->parent->parent->left)
		{
			rbtree_node *temp = node->parent->parent->right;

			if (rbt_is_red(temp)) // 叔叔结点为红色
			{
				rbt_black(node->parent);
				rbt_black(temp);
				rbt_red(node->parent->parent);
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->right)
				{
					node = node->parent;
					rbtree_left_rotate(root, sentinel, node);
				}

				rbt_black(node->parent);
				rbt_red(node->parent->parent);
				rbtree_right_rotate(root, sentinel, node->parent->parent);
			}
		}
		else
		{
			rbtree_node *temp = node->parent->parent->left;

			if (rbt_is_red(temp))	// 叔叔结点为红色
			{
				rbt_black(node->parent);
				rbt_black(temp);
				rbt_red(node->parent->parent);
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->left)
				{
					node = node->parent;
					rbtree_right_rotate(root, sentinel, node);
				}

				rbt_black(node->parent);
				rbt_red(node->parent->parent);
				rbtree_left_rotate(root, sentinel, node->parent->parent);
			}
		}
	}

	rbt_black(*root);
}

void rbtree_delete(rbtree *tree, rbtree_node *node)
{
	unsigned int red;
	rbtree_node *subst, *temp, *w;

	rbtree_node **root = &(tree->root);
	rbtree_node *sentinel = tree->sentinel;


	if (node->left == sentinel) // 左孩子结点为空
	{
		subst = node;
		temp = node->right;
	}
	else if (node->right == sentinel) // 右孩子结点为空
	{
		subst = node;
		temp = node->left;
	}
	else
	{
		subst = rbtree_min(node->right, sentinel); // 指向直接后继结点
		temp = subst->right;
	}

	if (subst == *root)
	{
		*root = temp;
		rbt_black(temp);

		/* DEBUG stuff */
		node->parent = NULL;
		node->left = NULL;
		node->right = NULL;
		node->key = 0;

		return;
	}

	red = rbt_is_red(subst);

	if (subst == node) // node结点至少有一个孩子结点为空
	{
		temp->parent = subst->parent;
		if (subst == subst->parent->left)
		{
			subst->parent->left = temp;
		}
		else
		{
			subst->parent->right = temp;
		}
	}
	else if (subst->parent == node)
	{
		rbt_copy_color(subst, node);
		subst->left = node->left;
		subst->parent = node->parent;

		if (node == *root)
		{
			*root = subst;
		}
		else
		{
			if (node == node->parent->left)
			{
				node->parent->left = subst;
			}
			else
			{
				node->parent->right = subst;
			}
		}

		if (subst->left != sentinel)
		{
			subst->left->parent = subst;
		}
	}
	else
	{
		temp->parent = subst->parent;
		if (subst == subst->parent->left)
		{
			subst->parent->left = temp;
		}
		else
		{
			subst->parent->right = temp;
		}

		rbt_copy_color(subst, node);
		subst->left = node->left;
		subst->right = node->right;
		subst->parent = node->parent;

		if (node == *root)
		{
			*root = subst;
		}
		else
		{
			if (node == node->parent->left)
			{
				node->parent->left = subst;
			}
			else
			{
				node->parent->right = subst;
			}
		}

		if (subst->left != sentinel)
		{
			subst->left->parent = subst;
		}

		if (subst->right != sentinel)
		{
			subst->right->parent = subst;
		}
	}

	/* DEBUG stuff */
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->key = 0;

	if (red)
	{
		return;
	}

	while (temp != *root && rbt_is_black(temp)) {

		if (temp == temp->parent->left) {
			w = temp->parent->right;

			if (rbt_is_red(w)) {
				rbt_is_black(w);
				rbt_is_red(temp->parent);
				rbtree_left_rotate(root, sentinel, temp->parent);
				w = temp->parent->right;
			}

			if (rbt_is_black(w->left) && rbt_is_black(w->right)) {
				rbt_red(w);
				temp = temp->parent;

			}
			else {
				if (rbt_is_black(w->right)) {
					rbt_black(w->left);
					rbt_red(w);
					rbtree_right_rotate(root, sentinel, w);
					w = temp->parent->right;
				}

				rbt_copy_color(w, temp->parent);
				rbt_black(temp->parent);
				rbt_black(w->right);
				rbtree_left_rotate(root, sentinel, temp->parent);
				temp = *root;
			}

		}
		else {
			w = temp->parent->left;

			if (rbt_is_red(w)) {
				rbt_black(w);
				rbt_red(temp->parent);
				rbtree_right_rotate(root, sentinel, temp->parent);
				w = temp->parent->left;
			}

			if (rbt_is_black(w->left) && rbt_is_black(w->right)) {
				rbt_red(w);
				temp = temp->parent;

			}
			else {
				if (rbt_is_black(w->left)) {
					rbt_black(w->right);
					rbt_red(w);
					rbtree_left_rotate(root, sentinel, w);
					w = temp->parent->left;
				}

				rbt_copy_color(w, temp->parent);
				rbt_black(temp->parent);
				rbt_black(w->left);
				rbtree_right_rotate(root, sentinel, temp->parent);
				temp = *root;
			}
		}
	}

	rbt_black(temp);
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

static inline rbtree_node *rbtree_min(rbtree_node *node, rbtree_node *sentinel)
{
	while (node && node->left != sentinel)
	{
		node = node->left;
	}
	return node;
}