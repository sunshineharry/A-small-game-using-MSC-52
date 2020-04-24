#include "REG51.H"


void TIM_0_init(void)
{
    // 50ms 中断一次
    TMOD = TMOD | 0x01;     // 定时器0选择方式1工作
    TH0 = 0x3C;
    TL0 = 0xB0;             // 装入初值，50ms中断一次
    ET0 = 1;                // 打开 T0 中断
    EA = 1;                 // 打开总中断
    PT0 = 1;                // 设置高优先级
    TR0 = 0;                // T0 仅初始化，不启动
}

void TIM_0_continue(void)
{
    TH0 = 0x3C;
    TL0 = 0xB0;             // 重新装入初值，50ms中断一次
    TR0 = 1;                // T0 启动
}

void TIM_0_pause(void)
{
    TR0 = 0;                // T0 关闭
}

void TIM_1_init(void)
{
    // 计数器，累计两个脉冲产生中断
    TMOD = TMOD | 0x60;     // 计数器1选择方式2工作
    TH1 = 0xFE;
    TL1 = 0xFE;
    ET1 = 1;                // 打开 T1 中断
    EA = 1;                 // 打开总中断
    PT1 = 0;                // 设置低优先级
    TR1 = 1;                // T1 启动
}


void TIM_1_rrestart(void)
{
    TL1 = 0xFE;             // T1 重装
}