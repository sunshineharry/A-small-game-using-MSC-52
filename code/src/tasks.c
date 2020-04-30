#include "reg52.h"
#include "LCD_func.h"
#include "keyboard_func.h"
#include "interrupt_func.h"
#include "random_func.h"
#define uchar unsigned char
extern void update(void);
extern uchar score;


/********************************************************************************************
                                        延时500ms
********************************************************************************************/
void delay500ms(void)
{
    unsigned char a,b,c;
    for(c=23;c>0;c--)
        for(b=152;b>0;b--)
            for(a=70;a>0;a--);
}


/********************************************************************************************
                                        暂停与继续
********************************************************************************************/
bit is_pause = 0;                       // 暂停时的标志位，is_pause = 1 表示处于暂停状态

// INT1 中断，手动设置低优先级
void pause() interrupt 2
{
    P0 = 0x00;                          // LED 点阵熄灭
    is_pause = 1;                       // 更新标志位
    LCD_clear(0);
    LCD_display(0x80,"   PAUSE");       // 更新 LCD 显示屏
    init_random(TL1);                   // 重新获取随机数
    while(is_pause);                    // 当 "CONTINUE" 按下前，标志位一直为 1
                                        //  "CONTINUE" 按下后，标志位清零，退出无限循环，继续游戏
}

// INT0 中断，手动设置高优先级
void continuee() interrupt 0
{
    if (is_pause == 0)                  // 当之前没有按下"PAUSE"键，不做任何反应
        return;
    LCD_clear(0);                       // 更新显示屏并暂留
    LCD_display(0x80,"CONTINUE");
    delay500ms();
    LCD_display(0x80,"Score:     ");    // 显示屏恢复暂停前的状态
    LCD_display(0xC2,uchar2string(score));
    is_pause = 0;                       // 更新标志位，使之退出pause中断
}


/********************************************************************************************
                                    正常运行
********************************************************************************************/
uchar count = 0;                        // 计数变量，当 count = 10 使表示半秒

// 正常情况每半秒钟更新
void TIM_0_isr() interrupt 1
{
    TH0 = (65536 - 50000) / 256;        // 定时器手动重装
    TL0 = (65536 - 50000) % 256;
    count++;
    if (count==10)                      // 半秒时间到
    {
        count = 0;                      // 清空标志位
        update();                       // 调用update函数，执行主逻辑
    }
}