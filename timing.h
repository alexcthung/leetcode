#ifndef __TIMING_H__
#define __TIMING_H__
#include <time.h>
#include <sys/time.h>

inline float timeuse_count(struct timeval start, struct timeval end)
{
    return (float)((end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec - start.tv_usec))/1000000;
}

#endif
