#ifndef _AVL_TREE_H
#define _AVL_TREE_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"

typedef struct AvlNode_s
{
	void *data;
	long height;
        struct AvlNode_s *left;
        struct AvlNode_s *right; 
}AvlNode_t;

typedef int (*AvlCmpFn_t)(void *data1, void *data2);
typedef void (*AvlIterFn_t)(AvlNode_t *n);
typedef void (*AvlFreeFn_t)(AvlNode_t *n);

typedef struct AvlTree_s
{
	AvlNode_t *root;
	AvlCmpFn_t cmp_fn;	
	AvlIterFn_t iter_fn;
	AvlFreeFn_t free_fn;
}AvlTree_t;

#define init_avl_node(n) \
	do { \
	(n)->data = NULL; \
	(n)->height = 0; \
	(n)->left = NULL; \
	(n)->right = NULL; \
	} while (0)

static inline long avl_node_height(AvlNode_t* n)
{
	if (n == NULL)
	{
		return 0;
	}
	else
	{
		return n->height;
	}
}

static inline AvlNode_t* left_left_rotation(AvlNode_t *n)
{
        AvlNode_t *pLeft = n->left;

        n->left = pLeft->right;
        pLeft->right = n;
        n->height = max(avl_node_height(n->left), avl_node_height(n->right)) + 1;
        pLeft->height = max(avl_node_height(pLeft->left), avl_node_height(pLeft->right)) + 1;

        return pLeft;
}

static inline AvlNode_t* right_right_rotation(AvlNode_t *n)
{
        AvlNode_t *pRight = n->right;

        n->right = pRight->left;

        pRight->left = n;
        n->height = max(avl_node_height(n->left), avl_node_height(n->right)) + 1;
        pRight->height = max(avl_node_height(pRight->left), avl_node_height(pRight->right)) + 1;

        return pRight;
}

static inline AvlNode_t* left_right_rotation(AvlNode_t *n)
{
        AvlNode_t *pLeft = n->left;

        n->left = right_right_rotation(pLeft);
        return left_left_rotation(n);
}

static inline AvlNode_t* right_left_rotation(AvlNode_t *n)
{
        AvlNode_t *pRight = n->right;

        n->right = left_left_rotation(pRight);
        return right_right_rotation(n);
}

AvlTree_t* avltree_create(AvlCmpFn_t cmp_fn, AvlIterFn_t iter_fn, AvlFreeFn_t free_fn);
AvlNode_t* avlnode_create(void *data);
AvlNode_t* avlnode_insert(AvlTree_t *tree, AvlNode_t **root, void *data);
AvlNode_t* avltree_min(AvlNode_t *root);
AvlNode_t* avltree_max(AvlNode_t *root);
AvlNode_t* avlnode_delete(AvlTree_t *tree, AvlNode_t **root, void *data);
AvlNode_t* avltree_search(AvlTree_t *tree, void *data);
void avltree_preorder(AvlTree_t *tree, AvlNode_t *root);
void avltree_inorder(AvlTree_t *tree, AvlNode_t *root);
void avltree_postorder(AvlTree_t *tree, AvlNode_t *root);
#endif
