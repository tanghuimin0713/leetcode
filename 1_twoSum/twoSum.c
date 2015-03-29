#include "twoSum.h"

int idx[2] = {-1, -1};
int *twoSum(int numbers[], int n, int target)
{
	int idx1 = 0, idx2 = -1;

	quickSort(numbers, 0, n -1 );

	while ((numbers[idx1] <= (target >> 1)) && ((idx1 + 1) < n))
	{
		idx2 = binarySearch(numbers + idx1 + 1, n - idx1 - 1, target - numbers[idx1]);	
		if (idx2 != -1)
		{
			idx[0] = idx1 + 1;
			idx[1] = idx1 + 1 + idx2 + 1;
			return idx;
		}
		else
		{
			idx1++;
		}
	}
	return NULL;
}
