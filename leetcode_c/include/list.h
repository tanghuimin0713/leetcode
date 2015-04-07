#ifndef _LIST_H
#define _LIST_H

#include <stddef.h>
#include "common.h"

struct hlist_node
{
	struct hlist_node *next, **pprev;
};

struct hlist_head
{
	struct hlist_node *first;
};

#define INIT_HASH_HEAD(ptr)	((ptr)->first = NULL)

static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h)
{
	struct hlist_node *first = h->first;
	n->next = first; 
	if (first)
	{
		first->pprev = &n->next;	
	}
	h->first = n;
	n->pprev = &h->first;
}

static inline void hlist_del(struct hlist_node *n)
{
	struct hlist_node *next = n->next;
	struct hlist_node **pprev = n->pprev;
	*pprev = next;
	if (next)
	{
		next->pprev = pprev;
	}
	n->next = NULL;
	n->pprev = NULL;
}

#define hlist_entry(ptr, type, member)	container_of(ptr, type, member)

#define hlist_for_each_entry(tpos, pos, head, member) \
	for (pos = (head)->first; pos && \
		(tpos = hlist_entry(pos, typeof(*tpos), member)); \
		pos = pos->next)
#endif
