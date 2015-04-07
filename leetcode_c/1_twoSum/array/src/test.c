#include "test.h" 

void test_partition()
{
	int32_t array[ARRAY_SIZE] = {0};
	int32_t i = 0;
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
		p_numInfo[i].key = (int64_t)(array[i]);
	}
	partition(p_numInfo, 0, ARRAY_SIZE-1);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", (int32_t)(p_numInfo[i].key));
	}
}

void test_quickSort()
{
	int32_t array[ARRAY_SIZE] = {0};
	int32_t i = 0;
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
		p_numInfo[i].key = (int64_t)array[i];
	}
	quickSort(p_numInfo, 0, ARRAY_SIZE-1);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", (int32_t)p_numInfo[i].key);
	}
}

void test_binarySearch()
{
	int32_t array[ARRAY_SIZE] = {0};
	int32_t key = 0;
	int32_t pos = -1;
	int32_t i = 0;
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
		p_numInfo[i].key = (int64_t)(array[i]);
		if ((p_numInfo[i].info = malloc(sizeof(int32_t))) == NULL)
		{
			printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
			free(p_numInfo);
			return;
		}
		memcpy(p_numInfo[i].info, &i, sizeof(int32_t));
		p_numInfo[i].info_len = sizeof(int32_t);
	}

	quickSort(p_numInfo, 0, ARRAY_SIZE-1);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", (int32_t)p_numInfo[i].key);
	}

	pos = binarySearch(p_numInfo, ARRAY_SIZE, (int64_t)key);
	printf("\n%d ", (pos == -1) ? -1 : *(int32_t *)(p_numInfo[pos].info));
}

extern int32_t idx[2];
void test_twoSum()
{
	int32_t numbers[ARRAY_SIZE] = {0};
	int32_t target = 0;
	int32_t i = 0;

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
