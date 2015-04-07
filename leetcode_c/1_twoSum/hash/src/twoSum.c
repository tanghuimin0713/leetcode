#include "twoSum.h"

int idx[2] = {-1, -1};

int *twoSum(int numbers[], int n, int target)
{
	uint32_t i = 0;
	int idx1 = -1, idx2 = -1;
	hashNode_t *node = NULL;

	init_num_hash(numbers, n);
	
	for (i = 0; i < n; i++)
	{
		node = search_num_hash(target - numbers[i], n);
		if (node != NULL)
		{
			idx1 = i;
			idx2 = *(uint32_t *)(node->info);
			if (idx1 > idx2)
			{
				uint32_t tmp = 0;
				tmp = idx1;
				idx1 = idx2;
				idx2 = tmp;
			}
			idx[0] = (idx1 + 1);
			idx[1] = (idx2 + 1);
			break;
		}
	}

	free_num_hash(n);
	return idx;
}
