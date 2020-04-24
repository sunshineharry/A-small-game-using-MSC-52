#include "REG51.H"

// 外中断初始化函数
void EX0_init()
{
    IT0 = 1;    // 下降沿触发
    PX0 = 1;    // 高优先级
    EX0 = 1;    // 单个中断允许
    EA = 1;     // 总中断运行
}