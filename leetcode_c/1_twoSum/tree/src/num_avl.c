#include "num_avl.h"

int CmpNumInfo(void *numInfo1, void *numInfo2)
{
	numInfo_t *info1 = (numInfo_t *)numInfo1;
	numInfo_t *info2 = (numInfo_t *)numInfo2;

	if (info1->num > info2->num)
	{
		return 1;
	}
	else if(info1->num < info2->num)
	{
		return -1;
	}
	else
	{
		return 0;	
	}
}

void PrintNumInfo(void *numInfo)
{
	numInfo_t *info = (numInfo_t *)numInfo;
	printf("num = %d, index = %d\n", info->num, info->index);
}

AvlTree_t* num_avl_tree_create()
{
	return avltree_create(CmpNumInfo, PrintNumInfo);	
}

AvlNode_t* num_avl_node_insert(AvlTree_t *tree, int num, unsigned int index)
{
	numInfo_t *numInfo = NULL;
	if ((numInfo = malloc(sizeof(numInfo_t))) == NULL)
	{
		return NULL;
	}
	numInfo->num = num;
	numInfo->index = index;
	return avlnode_insert(tree, tree->root, numInfo);
}

void num_avl_tree_print_preorder(AvlTree_t *tree)
{
	avltree_preorder(tree, tree->root);
}

void num_avl_tree_print_inorder(AvlTree_t *tree)
{
	avltree_inorder(tree, tree->root);
}

void num_avl_tree_print_postorder(AvlTree_t *tree)
{
	avltree_postorder(tree, tree->root);
}
