#include "REG51.H"
#include "interrupt_func.h"

void init()     // 初始化定时器和计数器
{
    TIM_0_init();
    TIM_1_init();
}


void main()
{
    init();
    P1 = 0xFF;  // 上电LED全部熄灭
    while(1);
}

