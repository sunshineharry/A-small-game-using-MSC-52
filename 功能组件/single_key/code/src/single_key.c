# include"single_key.h"


bit is_single_key_press()
{
    bit is_press = 0;
    unsigned char flag = 0;
    if (key0 == 0 && flag == 0)
        flag = 1;
    if (key0 == 1 && flag == 1)
        is_press = 1;
    return is_press;
}