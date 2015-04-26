#include "twoSum.h"

int idx[2] = {-1, -1};

int *twoSum(int numbers[], int n, int target)
{
	int i = 0;
	int idx1 = -1, idx2 = -1;
	AvlTree_t *tree = NULL;
	AvlNode_t *node = NULL;

	if ((tree = num_avl_tree_create()) == NULL)
	{
		printf("%s, %d: num_avl_tree_create failed.\n", __FUNCTION__, __LINE__);
		return idx;
	}

	for (i = 0; i < n; i++)
	{
		num_avl_node_insert(tree, numbers[i], i);
	}
	
	for (i = 0; i < n; i++)
	{
		node = num_avl_tree_search(tree, target - numbers[i]);
		if (node != NULL)
		{
			idx1 = i;
			idx2 = ((numInfo_t *)(node->data))->index;
			if (idx1 > idx2)
			{
				int tmp = 0;
				tmp = idx1;
				idx1 = idx2;
				idx2 = tmp;
			}
			idx[0] = (idx1 + 1);
			idx[1] = (idx2 + 1);
			break;
		}
	}

	num_avl_tree_destory(tree);
	return idx;
}
