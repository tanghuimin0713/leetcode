#include "quickSort.h"

int partition(int *R, int low, int high)
{
	assert(R != NULL);

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

void quickSort(int *R, int low, int high)
{
	assert(R != NULL);

	int pivotPos = 0;
	if (low < high)
	{
		pivotPos = partition(R, low, high);
		if (low < (pivotPos - 1))
		{
			quickSort(R, low, pivotPos - 1);
		}
		if ((pivotPos + 1) < high)
		{
			quickSort(R, pivotPos + 1, high);
		}
	}
}
