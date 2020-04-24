// 预处理指令，通过 DEBUG 宏控制 gdb 调试或 keil 编译
#define DEBUG 0
#if DEBUG
    #include "stdio.h"
    #define uchar int
#else
    #include "reg51.h"
    #define uchar unsigned char
#endif

uchar s[10]={0x10,0x35,0xa3,0xf7,0x2d,0x9d,0xe8,0x04,0x87,0xd0};    // 10个无符号数
uchar MAX = 0, MIN = 0, SUM = 0, BCDH = 0, BCDL = 0, AVG = 0;       // 存储结果

void maxx(void)     // 找到最大值，keil 当中不允许函数和变量同名（忽略大小写）
{
    uchar i = 0;
    MAX = s[0];
    for(i=1;i<10;i++)
    {
        if(s[i]>MAX)
            MAX = s[i];
    }
}

void minn(void)     // 找到最小值
{
    uchar i = 0;
    MIN = s[0];
    for(i=1;i<10;i++)
    {
        if(s[i]<MIN)
            MIN = s[i];
    }
}

void mean(void)
{
    uchar i = 0;
    int sum = 0;
    for(i=0;i<10;i++)
        sum += s[i];
    AVG = (sum-MAX-MIN)/8;
}

void DEC_2_BCD(void)
{
    uchar tmp = 0;
    if (SUM>100)
        BCDH = SUM / 100;           // 百位送入 BCDH
    BCDL = SUM % 10;                // 个位送入 BCDL 的低4位 
    tmp = ((SUM -BCDL)/10) % 10;
    tmp = tmp<<4;
    BCDL += tmp;                    // 十位送入 BCDL 的高4位 
    
}

void main()
{
    maxx();
    minn();
    SUM = MAX + MIN;
    mean();
    DEC_2_BCD();
}


