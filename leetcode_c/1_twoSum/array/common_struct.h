#ifndef _COMMON_H
#define _COMMON_H

#include <stdint.h>

typedef struct numInfo_s
{
	int64_t key;
	void *info;
	uint32_t info_len;
}numInfo_t;

#endif
