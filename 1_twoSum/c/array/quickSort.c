#include "quickSort.h"

int partition(numInfo_t *R, int low, int high)
{
	assert(R != NULL);

	numInfo_t pivot = R[low];
	while (low < high)
	{
		while ((low < high) && (pivot.number <= R[high].number))
		{
			high--;
		}
		R[low] = R[high];

		while ((low < high) && (pivot.number >= R[low].number))
		{
			low++;
		}
		R[high] = R[low];
	}

	R[low] = pivot;
	return low;
}

void quickSort(numInfo_t *R, int low, int high)
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
