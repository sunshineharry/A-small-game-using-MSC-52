#include "REG51.H"
#include "single_key_fun.h"

unsigned char s[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x7F,0x6F};
unsigned char num = 0;



void seg()
{
    P2 = s[num];
}

void main()
{
    while (1)
    {
        if(is_single_key_press())
        {
            num++;
            seg();
        }
        
    }
    
}
