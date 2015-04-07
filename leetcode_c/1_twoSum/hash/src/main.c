#include "test.h"
#include "twoSum.h"

#define MAX_SIZE 6
extern int32_t idx[2];
int main()
{
	//test_init_num_hash();
	//test_search_num_hash();
	uint32_t i = 0;
	int32_t array[MAX_SIZE] = {0};
	uint32_t array_size = MAX_SIZE;
	int32_t target = 0;

	printf("numbers:");
	for (i = 0; i < MAX_SIZE; i++)
	{
		scanf("%d", &array[i]);
	}
	printf("target:");
	scanf("%d", &target);

	twoSum(array, array_size, target);

	printf("output:idx1 = %d, idx2 = %d\n", idx[0], idx[1]);
	return 0;

}
