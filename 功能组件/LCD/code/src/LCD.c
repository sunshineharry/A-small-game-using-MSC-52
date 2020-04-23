#include "reg51.h"
#include "LCD.h"


void delay()
{
    uchar j=0;
    for(j=0;j<255;j++);
}

void write_char(uchar dat)
{
    // 根据时序图
    RS = 1;
    RW = 0;
    E  = 0;
    LCD_PORT = dat;
    delay();
    delay();
    E = 1;
    E = 0;
}

void write_cmd(uchar command)
{
    RS = 0;
    RW = 0;
    E  = 0;
    LCD_PORT = command;
    delay();
    E = 1;
    E = 0;
}

void init_LCD()
{
    write_cmd(0x38);    // 设置16×2显示，5×7点阵，8位数据接口
    write_cmd(0x0c);    // 设置开显示，不显示光标
    write_cmd(0x06);    // 写一个字符后地址指针加1
    write_cmd(0x01);    // 显示清0，数据指针清0
}


/**
 * @brief  在屏幕上显示字符串  
 * @param  line: 需要显示的行数
 * @param  *str: 字符串的首地址
 */
void display_LCD(uchar line,char *str)
{
    uchar i = 0;
    if (line == 1)
        write_cmd(0x80);         // LCD第一行的起始地址
    if (line == 2)
        write_cmd(0x80+0x40);    // LCD第二行的起始地址
    while(str[i]!='\0')
    {
        write_char(str[i]);
        i++;
    }
}

void clear_LCD()
{
    write_cmd(0x01);    // 显示清0，数据指针清0
}

