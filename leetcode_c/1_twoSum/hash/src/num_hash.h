#ifndef _NUM_HASH_H
#define _NUM_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hash.h"

int32_t init_num_hash_head(uint32_t bucket_size);
hashNode_t *init_num_hash_node(int32_t value, uint32_t index);
void add_num_hash_node(hashNode_t *n, uint32_t bucket_size);
int32_t init_num_hash(int32_t *array, uint32_t array_size);
void free_num_hashNode(hashNode_t *n);
void free_num_hash_head(hashHead_t *h);
void free_num_hash(uint32_t bucket_size);
hashNode_t *search_num_hash(int32_t key, uint32_t bucket_size);

#endif
