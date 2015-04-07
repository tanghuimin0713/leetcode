#include "twoSum.h"

int32_t idx[2] = {-1, -1};

int32_t *twoSum(int32_t numbers[], int32_t n, int32_t target)
{
	uint32_t i = 0;
	int32_t idx1 = -1, idx2 = -1;
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
