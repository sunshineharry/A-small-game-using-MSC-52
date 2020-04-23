#include "REG52.H"
#include "intrins.h"
#define uchar unsigned char

// ÑÓÊ± 500 ms
void delay(void)
{
    unsigned char a,b,c;
    for(c=205;c>0;c--)
        for(b=116;b>0;b--)
            for(a=9;a>0;a--);
}

void main()
{
	uchar i = 0;
    uchar ctrl_led = 0xfe
    while (1)
    {
        ctrl_led = _crol_(ctrl_led,1);
        P2 = ctrl_led;
        delay500ms();
    }
}
