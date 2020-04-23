#include"stdlib.h"

#define uchar unsigned char
#include "reg52.h"

// TODO 占用空间较大，待优化

void init_random(unsigned char seed)
{
    srand(seed);
}

uchar random(void)
{
    return rand()%15;
}

