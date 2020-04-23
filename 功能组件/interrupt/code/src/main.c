#include "REG51.H"
#include "interrupt.h"

unsigned char s[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x7F,0x6F};
unsigned char num = 0;

void init_ex0()
{
    IT0 = 1;
    EX0 = 1;
    EA = 1;
}

void main()
{
    init_ex0();
    while (1)
    {
        P2 = s[num];
        if (num == 10)
        {
            num = 0;
        }
    }
}

void ex_isr() interrupt 0
{
    num++;
}