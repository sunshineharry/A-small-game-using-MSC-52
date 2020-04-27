#include "REG52.H"
#include "keyboard.h"


unsigned char KEYBOARD_get_key()
{
    unsigned char key_num = 0xff;
    unsigned char tmp_1 = 0, tmp_2 = 0, flag = 0;
    KEY_PORT = 0xf0;
    // 检测按键是否被按下
    if (KEY_PORT != 0xf0)
    {
        tmp_1 = KEY_PORT;
        flag = 1;
        KEY_PORT = 0x0f;
    }
    if ((KEY_PORT != 0x0f) && (flag == 1))
    {
        tmp_2 = KEY_PORT;
        tmp_2 = 0x0f ^ tmp_2;
        key_num = tmp_1 + tmp_2;
    }
    return key_num;
}