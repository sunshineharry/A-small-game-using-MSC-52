// LCD显示屏外部接口函数声明
extern void LCD_init();
extern void LCD_display(unsigned char addr,char *str);
extern void LCD_clear(bit mode);
extern char* uchar2string(unsigned char n);