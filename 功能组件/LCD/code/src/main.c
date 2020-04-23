#include "LCD_func.h"

char str[] = {"Hello world!"};

void main()
{
    init_LCD();
    while (1)
    {
        display_LCD(1,&str);
        clear_LCD();
    }
    
}
