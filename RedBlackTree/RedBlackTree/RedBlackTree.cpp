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