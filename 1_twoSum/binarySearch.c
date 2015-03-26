#include "binarySearch.h"

int BinarySearch(int *R, int size, int K)
{
	int low = 0, high = (size-1);
	int mid = 0;

	while(low <= high)
	{
		mid = (low+high)/2;
		if (R[mid] == K)	
		{
			return mid;
		}
		else if (R[mid] > K)
		{
			high = (mid-1);
		}
		else
		{
			low = (mid+1);
		}
	}

	return -1;
}
