#include "test.h" 

void test_partition()
{
	int array[ARRAY_SIZE] = {0};
	int i = 0;
	numInfo_t *p_numInfo = NULL;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		scanf("%d", &array[i]);
	}

	if ((p_numInfo = malloc(ARRAY_SIZE * sizeof(numInfo_t))) == NULL)
	{
		printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
		return;
	}
	memset(p_numInfo, 0, (ARRAY_SIZE * sizeof(numInfo_t)));
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		p_numInfo[i].index = i;
		p_numInfo[i].number = array[i];
	}

	partition(p_numInfo, 0, ARRAY_SIZE-1);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", p_numInfo[i].number);
	}
}

void test_quickSort()
{
	int array[ARRAY_SIZE] = {0};
	int i = 0;
	numInfo_t *p_numInfo = NULL;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		scanf("%d", &array[i]);
	}

	if ((p_numInfo = malloc(ARRAY_SIZE * sizeof(numInfo_t))) == NULL)
	{
		printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
		return;
	}
	memset(p_numInfo, 0, (ARRAY_SIZE * sizeof(numInfo_t)));
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		p_numInfo[i].index = i;
		p_numInfo[i].number = array[i];
	}
	quickSort(p_numInfo, 0, ARRAY_SIZE-1);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", p_numInfo[i].number);
	}
}

void test_binarySearch()
{
	int array[ARRAY_SIZE] = {0};
	int key = 0;
	int pos = -1;
	int i = 0;
	numInfo_t *p_numInfo = NULL;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		scanf("%d", &array[i]);
	}
	scanf("%d", &key);

	if ((p_numInfo = malloc(ARRAY_SIZE * sizeof(numInfo_t))) == NULL)
	{
		printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
		return;
	}
	memset(p_numInfo, 0, (ARRAY_SIZE * sizeof(numInfo_t)));
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		p_numInfo[i].index = i;
		p_numInfo[i].number = array[i];
	}

	quickSort(p_numInfo, 0, ARRAY_SIZE-1);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", p_numInfo[i].number);
	}

	pos = binarySearch(p_numInfo, ARRAY_SIZE, key);
	printf("\n%d ", (pos == -1) ? -1 : p_numInfo[pos].index);
}

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
