#include "hash.h"

void init_hashHead(hashHead_t *h, uint32_t n)
{
	assert(h != NULL);

	uint32_t i = 0;
	for (i = 0; i < n; i++)	
	{
		INIT_HASH_HEAD(&(h[i].hhead));
	}
}

uint32_t hash_hashNode(void *key, uint32_t key_len)
{
	return jhash(key, key_len, 0);
}

void add_hashNode(hashNode_t *n, hashHead_t *h)
{
	assert((n != NULL) && (h != NULL));

	hlist_add_head(&n->hlist, &h->hhead);
}

hashNode_t *search_hash_node(void *key, uint32_t key_len,  hashHead_t *h)
{
	assert((key != NULL) && (h != NULL));

	struct hlist_head *head = &(h->hhead);	
	struct hlist_node *n = NULL;
	hashNode_t *node = NULL;

	hlist_for_each_entry(node, n, head, hlist)
	{
		if (0 == memcmp(node->key, key, key_len))
		{
			return node; 
		}
	}
	return NULL;
}

void del_hashNode(hashNode_t *n)
{
	assert(n != NULL);
	hlist_del(&(n->hlist));
}

hashNode_t *get_hashNode(struct hlist_node *n)
{
	return hlist_entry(n, hashNode_t, hlist);
}

