#ifndef _NUMHASH_H
#define _NUMHASH_H

#include <assert.h>
#include <string.h>
#include "list.h"
#include "jhash.h"

typedef struct hashNode_s
{
	void *key;
	uint32_t key_len;
	void *info;
	uint32_t info_len;	
	struct hlist_node hlist;	
}hashNode_t;

typedef struct hashHead_s
{
	struct hlist_head hhead;
}hashHead_t;

void init_hashHead(hashHead_t *h, uint32_t n);
uint32_t hash_hashNode(void *key, uint32_t key_len);
void add_hashNode(hashNode_t *n, hashHead_t *h);
hashNode_t *search_hash_node(void *key, uint32_t key_len,  hashHead_t *h);
void del_hashNode(hashNode_t *n);
hashNode_t *get_hashNode(struct hlist_node *n);

#endif
