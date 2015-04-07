#include "twoSum.h"

int32_t idx[2] = {-1, -1};
int32_t *twoSum(int32_t numbers[], int32_t n, int32_t target)
{
	int32_t idx1 = -1, idx2 = -1;
	int32_t i = 0;
	numInfo_t *p_numInfo = NULL;

	assert((numbers != NULL) && (n > 0));

	if ((p_numInfo = malloc(n * sizeof(numInfo_t))) == NULL)
	{
		printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
		return NULL;
	}
	memset(p_numInfo, 0, n * sizeof(numInfo_t));

	for (i = 0; i < n; i++)
	{
		p_numInfo[i].key = (int64_t)(numbers[i]);
		if ((p_numInfo[i].info = malloc(sizeof(int32_t))) == NULL)
		{
			printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
			free(p_numInfo);
			return NULL;
		}
		memcpy(p_numInfo[i].info, &i, sizeof(int32_t));
		p_numInfo[i].info_len = sizeof(int32_t);
	}

	quickSort(p_numInfo, 0, n - 1);

	idx1 = 0;
	while ((idx1 + 1) < n)
	{
		idx2 = binarySearch(p_numInfo + idx1 + 1, n - idx1 - 1, (int64_t)target - p_numInfo[idx1].key);	
		if (idx2 != -1)
		{
			idx[0] = *(int32_t *)(p_numInfo[idx1].info) + 1;
			idx[1] = *(int32_t *)(p_numInfo[idx1 + 1 + idx2].info) + 1;
			if (idx[0] > idx[1])
			{
				int32_t tmp = 0;
				tmp = idx[0];	
				idx[0] = idx[1];
				idx[1] = tmp;
			}
			free(p_numInfo);
			return idx;
		}
		else
		{
			idx1++;
		}
	}
	free(p_numInfo);	
	return NULL;
}
