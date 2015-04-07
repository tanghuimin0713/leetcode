#include "binarySearch.h"

int32_t binarySearch(numInfo_t *R, int32_t size, int64_t K)
{
	assert((R != NULL) && (size > 0));

	int32_t low = 0, high = (size - 1);
	int32_t mid = -1;

	while(low <= high)
	{
		mid = ((low+high) >> 1);
		if (R[mid].key == K)	
		{
			return mid;
		}
		else if (R[mid].key > K)
		{
			high = (mid - 1);
		}
		else
		{
			low = (mid + 1);
		}
	}

	return -1;
}
