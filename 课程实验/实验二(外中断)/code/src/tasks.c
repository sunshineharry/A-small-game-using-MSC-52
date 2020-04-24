#include "REG51.H"
#define uchar unsigned char

uchar i = 0;
sbit LED = P1^0;

void continuee() interrupt 0
{
    i++;
    if(i == 3)
    {
        i = 0;
        LED = ~LED;
    }
}