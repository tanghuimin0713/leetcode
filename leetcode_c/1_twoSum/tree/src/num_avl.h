#ifndef _NUM_AVL_H
#define _NUM_AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "avl_tree.h"

typedef struct numInfo_s
{
	int num;
	unsigned int index;
}numInfo_t;

AvlTree_t* num_avl_tree_create();
AvlNode_t* num_avl_node_insert(AvlTree_t *tree, int num, unsigned int index);
AvlNode_t* num_avl_node_delete(AvlTree_t *tree, int num);
void num_avl_tree_destory(AvlTree_t *tree);
AvlNode_t* num_avl_tree_search(AvlTree_t *tree, int num);
void num_avl_tree_print_preorder(AvlTree_t *tree);
void num_avl_tree_print_inorder(AvlTree_t *tree);
void num_avl_tree_print_postorder(AvlTree_t *tree);

#endif
