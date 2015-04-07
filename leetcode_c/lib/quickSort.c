#include "quickSort.h"

int32_t partition(numInfo_t *R, int32_t low, int32_t high)
{
	assert(R != NULL);

	numInfo_t pivot = R[low];
	while (low < high)
	{
		while ((low < high) && (pivot.key <= R[high].key))
		{
			high--;
		}
		R[low] = R[high];

		while ((low < high) && (pivot.key >= R[low].key))
		{
			low++;
		}
		R[high] = R[low];
	}

	R[low] = pivot;
	return low;
}

void quickSort(numInfo_t *R, int32_t low, int32_t high)
{
	assert(R != NULL);

	int32_t pivotPos = 0;
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
