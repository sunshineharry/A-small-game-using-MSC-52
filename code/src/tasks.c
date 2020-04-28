#include "reg52.h"
#include "LCD_func.h"
#include "keyboard_func.h"
#include "interrupt_func.h"
#include "random_func.h"
#define uchar unsigned char
void update(void);
extern uchar random_num;
uchar score = 0;                        // 记录得分


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
// 正常情况每半秒钟更新
void TIM_0_isr() interrupt 1
{
    static uchar count = 0;             // 计数变量，当 count = 10 使表示半秒
    TH0 = (65536 - 50000) / 256;        // 定时器手动重装
    TL0 = (65536 - 50000) % 256;
    count++;
    if (count==10)                      // 半秒时间到
    {
        count = 0;                      // 清空标志位
        update();                       // 调用update函数，执行主逻辑
    }
}

// update 函数实现
// 每半秒钟更新信息
void update()
{
    // 定义变量
    uchar i = 0, j = 0;                 // 循环变量
    static uchar error = 0;             // 错误次数
    

    uchar decode = 0;                   // 随机数所对应的键盘及点阵的编码
                                        //   eg). 0b 10111000  表示第三行第四列

    uchar code_dic[]                    /* 编码字典*/
        = {0xe1,0xb4,0xe2,0xb2,0xd1,0xd4,0xd8,0xe8,0x72,0xb1,0xb8,0x71,0xd2,0x74,0xe4,0x78};

    // 获取随机数，并获取随机数对应编码
    if(random_num<0 || random_num>15)
        random_num = 0;
    decode = code_dic[random_num];

    // 点亮点阵
    P0 = decode;

    // 连续扫描键盘，当检测到对应按键时，取得分数
    // 连续三次没有按对按键，结束游戏
    for (i=0;i<255;i++)
    {
        for (j=0;j<150;j++)
        {
            if(decode == KEYBOARD_get_key())
            {
                score++;                // 检测到正确按键，更新分数
                error = 0;              // 清空错误次数
                P0 = 0x00;              // 关闭 LED 点阵
                goto LABAL;             // 直接跳转到更新屏幕分数显示
            }
        }
    }
    error++;
    if (error>3)
    {
        LCD_clear(0);                   // 清空LCD
        P0 = 0x00;                      // 关闭 LED 点阵
        LCD_display(0x80,"FAIL!");
        while(1);
    }

    // 刷新屏幕
    LABAL:LCD_display(0xC2,uchar2string(score));
}