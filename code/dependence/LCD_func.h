extern void init_LCD();
extern void display_LCD(unsigned char addr,char *str);
extern void clear_LCD(bit mode);
extern void display_LCD_single(unsigned char addr ,char str);
extern void delay(void);
extern char* uchar2string(unsigned char n);