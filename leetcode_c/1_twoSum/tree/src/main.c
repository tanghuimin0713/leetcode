#include "test.h"
#include "twoSum.h"

#define MAX_SIZE 6
extern int idx[2];
int main()
{
#if 0
	//test_avltree_build();
	//test_avltree_print(0);
	//test_avltree_delete();
	//test_avltree_destory();
	//test_avltree_print(0);
	//test_avltree_search();
#else
	int i = 0;
	int array[MAX_SIZE] = {0};
	int array_size = MAX_SIZE;
	int target = 0;

	printf("numbers:");
	for (i = 0; i < MAX_SIZE; i++)
	{
		scanf("%d", &array[i]);
	}
	printf("target:");
	scanf("%d", &target);

	twoSum(array, array_size, target);

	printf("output:idx1 = %d, idx2 = %d\n", idx[0], idx[1]);
#endif
	return 0;

}
