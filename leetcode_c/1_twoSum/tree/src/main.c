#include "num_avl.h"

#define MAX_SIZE 1
int array[MAX_SIZE] = {1};

int main()
{
	int i = 0;
	AvlTree_t *tree = NULL;
	tree = num_avl_tree_create();	

	for (i = 0; i < MAX_SIZE; i++)
	{
		num_avl_node_insert(tree, array[i], i);
	}

#if 1	
	printf("preorder:\n");
	num_avl_tree_print_preorder(tree);
	printf("inorder:\n");
	num_avl_tree_print_inorder(tree);
	printf("postorder:\n");
	num_avl_tree_print_postorder(tree);
#endif
	return 0;
}
