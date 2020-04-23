#include "REG52.H"
void EX0_init()
{
    IT0 = 1;    // 下降沿触发
    PX0 = 1;    // 高优先级
    EX0 = 1;    // 单个中断允许
    EA = 1;     // 总中断运行
}

void EX1_init()
{
    IT1 = 1;
    PX1 = 0;
    EX1 = 1;
    EA = 1;
}

void TIM_0_init(void)
{
    // 初始化 TMOD 寄存器
    // 50ms 中断一次
    TMOD = TMOD | 0x01;
    TH0 = (65536 - 50000) / 256;
    TL0 = (65536 - 50000) % 256;
    ET0 = 1;
    EA = 1;
    TR0 = 1;
}

void TIM_1_init(void)
{
    // 初始化 TMOD 寄存器
    // 产生随机数
    TMOD = TMOD | 0x20;
    TH1 = 239;
    TL1 = 239;
    ET1 = 0;    //分钟短不允许
    TR1 = 1;    //开始计数
}