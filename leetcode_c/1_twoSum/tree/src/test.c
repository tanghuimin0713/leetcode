#include "test.h"

//#define MAX_SIZE 16  
//int array[MAX_SIZE] = {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
#define MAX_SIZE 5  
int array[MAX_SIZE] = {5,4,3,2,1};
AvlTree_t *tree = NULL;

void test_avltree_build()
{
	int i = 0;
	tree = num_avl_tree_create();	

	for (i = 0; i < MAX_SIZE; i++)
	{
		num_avl_node_insert(tree, array[i], i);
	}
}

void test_avltree_print(int type)
{
	switch (type)
	{
		case 0:
			printf("preorder:\n");
			num_avl_tree_print_preorder(tree);
			break;
		case 1:	
			printf("inorder:\n");
			num_avl_tree_print_inorder(tree);
			break;
		case 2:
			printf("postorder:\n");
			num_avl_tree_print_postorder(tree);
			break;
		default:
			printf("type is between <0-2>");
	}
}

void test_avltree_delete()
{
	//int i = 0;

	//for (i = 0; i < MAX_SIZE; i++)
	//for (i = (MAX_SIZE - 1); i > 0; i--)
	{
	//	num_avl_node_delete(tree, array[i]);
		num_avl_node_delete(tree, 4);
		test_avltree_print(0);
	}
}

void test_avltree_destory()
{
	num_avl_tree_destory(tree);
}

void test_avltree_search()
{
	AvlNode_t *n = num_avl_tree_search(tree, 7);
	if (n)
	{
		tree->iter_fn(n);
	}
}
