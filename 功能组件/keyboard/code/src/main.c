#include "reg51.h"
#include "keyboard_func.h"

void main()
{
    unsigned char num = 0xff;
    while (1)
    {
        num = key_scan();
    }
    
}