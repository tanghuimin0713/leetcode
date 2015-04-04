#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H

#include <stdio.h>
#include <assert.h>
#include "common.h"

int partition(numInfo_t *R, int low, int high);
void quickSort(numInfo_t *R, int low, int high);

#endif
