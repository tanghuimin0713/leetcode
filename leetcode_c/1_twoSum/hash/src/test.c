#include "test.h"

#define MAX_SIZE 6
int32_t array[MAX_SIZE] = {0};
extern hashHead_t *num_hash_head;

void array_init()
{
	uint32_t i = 0;

	for (i = 0; i < MAX_SIZE; i++)
	{
		scanf("%d", &array[i]);
	}

	for (i = 0; i < MAX_SIZE; i++)
	{
		printf("%d", array[i]);
	}
	printf("\n");

}

void test_prepare()
{
	array_init();
}

void hash_print()
{
	uint32_t i = 0;
	struct hlist_node *n = NULL;
	hashNode_t *node = NULL;

	assert(num_hash_head != NULL);

	for (i = 0; i < MAX_SIZE; i++)
	{
		if ((num_hash_head+i)->hhead.first)
		{
			printf("index = %d: ", i);
			hlist_for_each_entry(node, n, &((num_hash_head+i)->hhead), hlist)
			{
				printf("key = %d, index = %d --->", 
						*(int32_t *)node->key, 
						*(uint32_t *)node->info);
			}
			printf("\n");
		}
	}
}

void test_restore()
{
	uint32_t bucket_size = MAX_SIZE;
	free_num_hash(bucket_size);	
}

void test_init_num_hash()
{
	uint32_t bucket_size = MAX_SIZE;

	test_prepare();
	init_num_hash(array, bucket_size);
	hash_print();
	test_restore();
}

void test_search_num_hash()
{
	hashNode_t *node = NULL;
	int32_t sel = 0;
	uint32_t bucket_size = MAX_SIZE;

	test_prepare();
	init_num_hash(array, bucket_size);
	hash_print();

	printf("input: ");
	scanf("%d", &sel);
	node = search_num_hash(sel, bucket_size);
	if (node == NULL)
	{
		printf("output: %d not exist.\n", sel);
	}
	else
	{
		printf("output: sel = %d, index = %d.\n", sel, *(uint32_t *)node->info);
	}

	test_restore();
}
