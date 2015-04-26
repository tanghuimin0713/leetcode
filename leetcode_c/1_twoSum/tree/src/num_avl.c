#include "num_avl.h"

int CmpNumInfo(void *numInfo1, void *numInfo2)
{
	assert((numInfo1 != NULL) && (numInfo2 != NULL));

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

void PrintNumInfo(AvlNode_t *n)
{
	assert(n != NULL);

	if (n->data)
	{
		numInfo_t *info = (numInfo_t *)(n->data);
		printf("num = %d, index = %d, height = %ld\n", info->num, info->index, n->height);
	}
	else
	{
		printf("height = %ld\n", n->height);
	}
}

void FreeAvlNode(AvlNode_t **n)
{
	if (n != NULL && *n != NULL)
	{
		if ((*n)->data != NULL)
		{
			free((*n)->data);
			(*n)->data = NULL;
		}
		free(*n);
		*n = NULL;
	}
}

AvlTree_t* num_avl_tree_create()
{
	return avltree_create(CmpNumInfo, PrintNumInfo, FreeAvlNode);	
}

AvlNode_t* num_avl_node_insert(AvlTree_t *tree, int num, unsigned int index)
{
	assert(tree != NULL);

	numInfo_t *numInfo = NULL;
	if ((numInfo = malloc(sizeof(numInfo_t))) == NULL)
	{
		printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
		return NULL;
	}
	numInfo->num = num;
	numInfo->index = index;
	return avlnode_insert(tree, &(tree->root), numInfo);
}

AvlNode_t* num_avl_node_delete(AvlTree_t *tree, int num)
{
	assert(tree != NULL);

	numInfo_t numInfo = {0};
	numInfo.num = num;

	return avlnode_delete(tree, &(tree->root), &numInfo);
}	

void num_avl_tree_destory(AvlTree_t *tree)
{
	avltree_destory(tree, &(tree->root));
}

AvlNode_t* num_avl_tree_search(AvlTree_t *tree, int num)
{
	assert(tree != NULL);

	numInfo_t numInfo = {0};
	AvlNode_t *n = NULL;

	numInfo.num = num;
	if ((n = avltree_search(tree, &numInfo)) == NULL)
	{
		printf("%s, %d: num:%d not exist.\n", __FUNCTION__, __LINE__, num);
	}
	return n;
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
