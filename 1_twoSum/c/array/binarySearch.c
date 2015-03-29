#include "binarySearch.h"

int binarySearch(numInfo_t *R, int size, int K)
{
	int low = 0, high = (size - 1);
	int mid = 0;

	while(low <= high)
	{
		mid = ((low+high) >> 1);
		if (R[mid].number == K)	
		{
			return mid;
		}
		else if (R[mid].number > K)
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