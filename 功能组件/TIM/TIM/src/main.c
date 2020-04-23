#include "REG51.H"

unsigned char s[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char count;
unsigned char num;

void init_TIM_0(void)
{
    // ³õÊ¼»¯ TMOD ¼Ä´æÆ÷
    TMOD = TMOD | 0x01;
    TH0 = (65536 - 50000) / 256;
    TL0 = (65536 - 50000) % 256;
    ET0 = 1;
    EA = 1;
    TR0 = 1;
}

void display()
{
    unsigned char tmp;
    tmp = num % 10;
    P2 = s[tmp];
}

void main()
{
    init_TIM_0();
    while (1)
    {
        display();
    }
    
}

void TIM_0_isr() interrupt 1
{
    TH0 = (65536 - 50000) / 256;
    TL0 = (65536 - 50000) % 256;
    count++;
    if (count==20)
    {
        num++;
        count = 0;
    }
}