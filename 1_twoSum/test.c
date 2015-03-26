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
