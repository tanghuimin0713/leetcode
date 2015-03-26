#include "quickSort.h"

int Partition(int *R, int low, int high)
{
	int pivot = R[low];

	while (low < high)
	{
		while ((low < high) && (pivot <= R[high]))
		{
			high--;
		}
		R[low] = R[high];

		while ((low < high) && (pivot >= R[low]))
		{
			low++;
		}
		R[high] = R[low];
	}

	R[low] = pivot;
	return low;
}

