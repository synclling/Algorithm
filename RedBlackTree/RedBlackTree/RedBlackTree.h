#pragma once

typedef struct rbtree_node
{
	unsigned int		key;
	struct rbtree_node *left;
	struct rbtree_node *right;
	struct rbtree_node *parent;
	char				color;
	char				data;
} rbtree_node;

typedef void(*rbtree_insert_pt)(rbtree_node *root, rbtree_node *node, rbtree_node *sentinel);

typedef struct rbtree
{
	rbtree_node *root;
	rbtree_node *sentinel;
	rbtree_insert_pt insert;
} rbtree;


#define rbt_red(node)			((node)->color = 1)
#define rbt_black(node)			((node)->color = 0)
#define rbt_is_red(node)		((node)->color)
#define rbt_is_black(node)		(!rbt_is_red(node))

/* a sentinel must be black */
#define rbtree_sentinel_init(node)		rbt_black(node)

void rbtree_init(rbtree *tree, rbtree_node *s, rbtree_insert_pt i);

void rbtree_insert(rbtree *tree, rbtree_node *node);

void rbtree_delete(rbtree *tree, rbtree_node *node);