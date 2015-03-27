#include "twoSum.h"

int index[2] = {-1, -1};
int *twoSum(int numbers[], int n, int target)
{
	quickSort(numbers, 0, n -1 );	
	while ((numbers[idx1] < (target >> 2)) && (idx < n))
	{
		idx2 = binarySearch(numbers + idx1 + 1, n - idx1 - 1, target - numbers[idx1]);	
		if (idx2 != 0)
		{
			index[0] = idx1 + 1;
			index[1] = idx2 + 1;
			return index;
		}
		else
		{
			idx1++;
		}
	}
}
