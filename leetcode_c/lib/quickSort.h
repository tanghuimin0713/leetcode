#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H

#include <stddef.h>
#include <assert.h>
#include "common_struct.h"

int32_t partition(numInfo_t *R, int32_t low, int32_t high);
void quickSort(numInfo_t *R, int32_t low, int32_t high);

#endif
