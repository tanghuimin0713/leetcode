#ifndef _COMMON_H
#define _COMMON_H

//#define offsetof(type, member) ((size_t)&(((type *)0)->member))

#define container_of(ptr, type, member)	({ \
	const typeof(((type *)0)->member) *__mptr = (ptr);\
	(type *)((char *)__mptr - offsetof(type, member));})

#define max(x, y) ({ \
	typeof(x) _max1 = x; \
	typeof(y) _max2 = y; \
	(void) (&_max1 == &_max2); \
	_max1 > _max2 ? _max1 : _max2; })	

#define min(x, y) ({ \
	typeof(x) _min1 = x; \
	typeof(y) _min2 = y; \
	(void) (&_min1 == &_min2); \
	_min1 < _min2 ? _min1 : _min2; })

#endif
