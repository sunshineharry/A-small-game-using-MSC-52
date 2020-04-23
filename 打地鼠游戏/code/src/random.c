#include"stdlib.h"

#define uchar unsigned char
#include "reg52.h"

// 利用自带函数产生随机数

void init_random(unsigned char seed)
{
    srand(seed);
}

uchar random(void)
{
    return rand()%15;
}

