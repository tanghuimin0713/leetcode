#include "test.h" 

#if 0
void test_partition()
{
	int array[ARRAY_SIZE] = {0};
	 int i = 0;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		scanf("%d", &array[i]);
	}

	partition(array, 0, ARRAY_SIZE-1);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", array[i]);
	}
}

void test_quickSort()
{
	int array[ARRAY_SIZE] = {0};
	 int i = 0;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		scanf("%d", &array[i]);
	}

	quickSort(array, 0, ARRAY_SIZE-1);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", array[i]);
	}
}

void test_binarySearch()
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

	quickSort(array, 0, ARRAY_SIZE-1);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", array[i]);
	}

	pos = binarySearch(array, ARRAY_SIZE, key);
	printf("\n%d ", pos);
}
#endif

extern int idx[2];
void test_twoSum()
{
	int numbers[ARRAY_SIZE] = {0};
	int target = 0;
	int i = 0;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		scanf("%d", &numbers[i]);
	}
	scanf("%d", &target);

	if (NULL != twoSum(numbers, ARRAY_SIZE, target))
	{
		printf("idx1 = %d, idx2 = %d\n", idx[0], idx[1]);
	}
	else
	{
		printf("not exist.\n");
	}
}
