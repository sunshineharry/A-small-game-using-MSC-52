#include "reg51.h"
#include "interrupt_func.h"
#define uchar unsigned char

uchar ctrl_led  = 0x01;

void press_twice() interrupt 3
{
    TIM_0_continue();
}

void shine_led() interrupt 1
{
    P1 = ctrl_led;
    ctrl_led = ctrl_led << 1;
    if (ctrl_led == 0x00)
        TIM_0_pause();
    else
        TIM_0_continue();
}