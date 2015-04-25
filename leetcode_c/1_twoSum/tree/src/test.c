#include "test.h"

#define MAX_SIZE 16  
int array[MAX_SIZE] = {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
AvlTree_t *tree = NULL;

void test_avltree_build()
{
	int i = 0;
	tree = num_avl_tree_create();	

	for (i = 0; i < MAX_SIZE; i++)
	{
		num_avl_node_insert(tree, array[i], i);
	}

	printf("preorder:\n");
	num_avl_tree_print_preorder(tree);
	printf("inorder:\n");
	num_avl_tree_print_inorder(tree);
	printf("postorder:\n");
	num_avl_tree_print_postorder(tree);
}
