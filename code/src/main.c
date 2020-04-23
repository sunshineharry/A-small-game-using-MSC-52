#include "reg52.h"
#include "LCD_func.h"
#include "keyboard_func.h"
#include "interrupt_func.h"
#include "random_func.h"

#define uchar unsigned char
extern void delay500ms(void);

// 初始化硬件配置
void init()
{
    init_LCD();         // LCD 初始化
    init_ex0();         // 外中断0
    init_ex1();
    init_TIM_0();
    init_TIM_1();       // 为了产生随机数
    init_random(TL1);
}

uchar random_num = 0;   // 随机数

void main()
{
    init();
    // 启动界面
    display_LCD(0x80,"Welcome");
    delay500ms();
    display_LCD(0x80,"Score:   ");
    while(1)
    {
        // 利用定时器生成随机数，主任务由中断引发
        random_num = random();
    }
}