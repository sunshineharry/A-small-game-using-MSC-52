#include "reg51.h"
#include "8155_func.h"
#define uchar unsigned char

uchar num_encode[] = /* 共阴极数码管前有反相器，使用共阳极编码*/
    {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};

uchar LED_num[] =   /* 选择哪个 LED 二极管亮，如果是 0 ，表示都熄灭*/
    {255,223,239,247,251,253,254};

void delay1ms(void)   //误差 0us
{
    unsigned char a,b,c;
    for(c=1;c>0;c--)
        for(b=142;b>0;b--)
            for(a=2;a>0;a--);
}

void main()
{
    uchar add_num_1 = 23;
    uchar add_num_2 = 46;
    uchar sum = add_num_1 + add_num_2;
    uchar tmp=0;

    C8155_init(0x0f);

    while(1)
    {
        tmp = add_num_1/10;
        C8155_PC = LED_num[1];
        C8155_PB = num_encode[tmp];
        delay1ms();

        tmp = add_num_1%10;
        C8155_PC = LED_num[2];
        C8155_PB = num_encode[tmp];
        delay1ms();

        tmp = add_num_2/10;
        C8155_PC = LED_num[3];
        C8155_PB = num_encode[tmp];
        delay1ms();

        tmp = add_num_2%10;
        C8155_PC = LED_num[4];
        C8155_PB = num_encode[tmp];
        delay1ms();

        tmp = sum/10;
        C8155_PC = LED_num[5];
        C8155_PB = num_encode[tmp];
        delay1ms();

        tmp = sum%10;
        C8155_PC = LED_num[6];
        C8155_PB = num_encode[tmp];
        delay1ms();
    }
    
}