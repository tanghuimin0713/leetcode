#include "twoSum.h"

int idx[2] = {-1, -1};
int *twoSum(int numbers[], int n, int target)
{
	int idx1 = -1, idx2 = -1;
	int i = 0;
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
		p_numInfo[i].index = i;
		p_numInfo[i].number = numbers[i];
	}

	quickSort(p_numInfo, 0, n - 1);

	idx1 = 0;
	while ((idx1 + 1) < n)
	{
		idx2 = binarySearch(p_numInfo + idx1 + 1, n - idx1 - 1, target - p_numInfo[idx1].number);	
		if (idx2 != -1)
		{
			idx[0] = p_numInfo[idx1].index + 1;
			idx[1] = p_numInfo[idx1 + 1 + idx2].index + 1;
			if (idx[0] > idx[1])
			{
				int tmp = 0;
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
