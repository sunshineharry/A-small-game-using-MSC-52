// LCD 液晶显示屏硬件接口函数

#include "reg52.h"
#include "LCD.h"


void _LCD_delay()
{
    uchar j=0,i=0;
    for(j=0;j<255;j++)
        for(i=0;i<4;i++);
}

void _LCD_write_char(uchar dat)
{
    // 根据时序图
    RS = 1;
    RW = 0;
    E  = 0;
    LCD_PORT = dat;
    _LCD_delay();
    E = 1;
    E = 0;
}

void _LCD_write_cmd(uchar command)
{
    RS = 0;
    RW = 0;
    E  = 0;
    LCD_PORT = command;
    _LCD_delay();
    E = 1;
    E = 0;
}

void LCD_init()
{
    _LCD_write_cmd(0x38);    // 设置16×2显示，5×7点阵，8位数据接口
    _LCD_write_cmd(0x0c);    // 设置开显示，不显示光标
    _LCD_write_cmd(0x06);    // 写一个字符后地址指针加1
    _LCD_write_cmd(0x01);    // 显示清0，数据指针清0
}


/**
 * @brief  在屏幕上显示字符串  
 * @param  addr: 需要显示首地址
 * @param  *str: 字符串的首地址
 */
void LCD_display(uchar addr,char *str)
{
    uchar i = 0;
    _LCD_write_cmd(addr);
    while(str[i]!='\0')
    {
        _LCD_write_char(str[i]);
        i++;
    }
}



/* mode=0：显示清零，指针清零
   mode=1: 仅指针清零   */
void LCD_clear(bit mode)
{
    if(mode == 0)
        _LCD_write_cmd(0x01);    // 显示清0，数据指针清0
    if(mode == 1)
        _LCD_write_cmd(0x02);
}


// 将 uchar 类型数字转成字符串
char str[4];
char* uchar2string(uchar n)
{

    uchar *pStr;
    pStr = str;
    if (n > 99)
    {
        *pStr = n / 100 + '0';
        n %= 100;
        pStr += 1;
        *pStr = n / 10 + '0';
        n %= 10;
        pStr += 1;
        *pStr = n + '0';
    }
    if (n > 9)
    {
        *pStr = n / 10 + '0';
        n %= 10;
        pStr += 1;
        *pStr = n + '0';
    }
    if (n < 10)
    {
        *pStr = n + '0';
    }
    pStr += 1;
    *pStr = '\0';
    return str;
}