#include "reg52.h"
#include "LCD_func.h"
#include "keyboard_func.h"
#include "interrupt_func.h"
#define uchar unsigned char

extern uchar random_num;


uchar score = 0;    // 记录得分

uchar decode = 0;   // 随机数所对应的键盘及点阵的编码
                    // 键盘与LED编码：
                    //   eg). 0b 10111000  表示第三行第四列

uchar code_dic[]   /* 编码字典*/
    = {0xe1,0xb4,0xe2,0xb2,0xd1,0xd4,0xd8,0xe8,0x72,0xb1,0xb8,0x71,0xd2,0x74,0xe4,0x78};


// 每半秒钟更新信息
void update()
{
    // 定义变量
    uchar i = 0, j = 0;         // 循环变量
    static uchar error = 0;     // 错误次数

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
                score++;        // 检测到正确按键，更新分数
                error = 0;      // 清空错误次数
                P0 = 0x00;      // 关闭 LED 点阵
                goto LABAL;     // 直接跳转到更新屏幕分数显示
            }
        }
    }
    error++;
    if (error>3)
    {
        LCD_clear(0);
        LCD_display(0x80,"FAIL!");
        while(1);
    }

    // 刷新屏幕
    LABAL:LCD_display(0xC2,uchar2string(score));
}