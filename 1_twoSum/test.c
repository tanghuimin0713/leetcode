#include "test.h" 

void test_Partition()
{
	int array[ARRAY_SIZE] = {0};
	 int i = 0;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		scanf("%d", &array[i]);
	}

	Partition(array, 0, ARRAY_SIZE-1);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", array[i]);
	}
}

void test_QuickSort()
{
	int array[ARRAY_SIZE] = {0};
	 int i = 0;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		scanf("%d", &array[i]);
	}

	QuickSort(array, 0, ARRAY_SIZE-1);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", array[i]);
	}
}

void test_BinarySearch()
{
	int array[ARRAY_SIZE] = {0};
	int key = 0;
	int pos = -1;
	int i = 0;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		scanf("%d", &array[i]);
	}
	scanf("%d", &key);

	QuickSort(array, 0, ARRAY_SIZE-1);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", array[i]);
	}

	pos = BinarySearch(array, ARRAY_SIZE, key);
	printf("\n%d ", pos);
}
