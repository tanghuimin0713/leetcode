#include "num_hash.h"

hashHead_t *num_hash_head = NULL;

int32_t init_num_hash_head(uint32_t bucket_size)
{
	if ((num_hash_head = malloc(sizeof(hashHead_t) * bucket_size)) == NULL)
	{
		printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
		return -1;
	}

	memset(num_hash_head, 0, sizeof(hashHead_t) * bucket_size);

	init_hashHead(num_hash_head, bucket_size);
	return 0;
}

hashNode_t *init_num_hash_node(int32_t value, uint32_t index)
{
	hashNode_t *n = NULL;

	if ((n = malloc(sizeof(hashNode_t))) == NULL)
	{
		printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
		return NULL;
	}
	memset(n, 0, sizeof(hashNode_t));

	if (((n->key) = malloc(sizeof(int32_t))) == NULL)
	{
		printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
		return NULL;
	}
	memcpy(n->key, &value, sizeof(int32_t));
	n->key_len = sizeof(int32_t);

	if ((n->info = malloc(sizeof(uint32_t))) == NULL)
	{
		printf("%s, %d: malloc failed.\n", __FUNCTION__, __LINE__);
		return NULL;
	}
	memcpy(n->info, &index, sizeof(uint32_t));
	n->info_len = sizeof(uint32_t);

	return n;
}

void add_num_hash_node(hashNode_t *n, uint32_t bucket_size)
{
	assert(n != NULL);

	uint32_t head_index;
	head_index = (hash_hashNode((uint8_t *)(n->key), n->key_len) & (bucket_size - 1));
	add_hashNode(n, num_hash_head + head_index);
}

int32_t init_num_hash(int32_t *array, uint32_t array_size)
{
	assert(array != NULL);

	uint32_t i = 0;
	hashNode_t *n = NULL;
	uint32_t bucket_size = array_size;

	if (init_num_hash_head(bucket_size) == -1)
	{
		printf("%s, %d: init_num_hash_head() failed.\n", __FUNCTION__, __LINE__);		
		return -1;
	}
	for (i = 0; i < array_size; i++)		
	{
		if ((n = init_num_hash_node(array[i], i)) == NULL)
		{
			printf("%s, %d: init_num_hash_node() failed.\n", __FUNCTION__, __LINE__);
			return -1;
		}	
		add_num_hash_node(n, bucket_size);		
	}
	return 0;
}

void free_num_hashNode(hashNode_t *n)
{
	assert(n != NULL);

	del_hashNode(n);
	free(n->key);
	n->key = NULL;
	free(n->info);
	n->info = NULL;
	free(n);
	n = NULL;
}

void free_num_hash_head(hashHead_t *h)
{
	assert(h != NULL);

	hashNode_t *node = NULL;
	while (h->hhead.first)
	{
		if ((node = get_hashNode(h->hhead.first)) != NULL)
		{
			free_num_hashNode(node);
		}
	}
}

void free_num_hash(uint32_t bucket_size)
{
	uint32_t i = 0;
	hashHead_t *head = NULL;

	for (i = 0; i < bucket_size; i++)
	{
		head = (num_hash_head + i);	
		if (head->hhead.first)	
		{
			free_num_hash_head(head);
		}
	}
	free(num_hash_head);	
	num_hash_head = NULL;
}

hashNode_t *search_num_hash(int32_t key, uint32_t bucket_size)
{
	uint32_t headIndex = hash_hashNode(&key, sizeof(int32_t)) & (bucket_size - 1); 
	return search_hash_node(&key, sizeof(int32_t), num_hash_head + headIndex);
}
