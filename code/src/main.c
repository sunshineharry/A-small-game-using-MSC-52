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
    LCD_init();         // LCD 初始化
    EX0_init();         // 外中断0
    EX1_init();
    TIM_0_init();
    TIM_1_init();       // 为了产生随机数
    init_random(TL1);
}

uchar random_num = 0;   // 随机数

void main()
{
    init();
    // 启动界面
    LCD_display(0x80,"Welcome");
    delay500ms();
    LCD_display(0x80,"Score:   ");
    while(1)
    {
        // 利用定时器生成随机数，主任务由中断引发
        random_num = random();
    }
}