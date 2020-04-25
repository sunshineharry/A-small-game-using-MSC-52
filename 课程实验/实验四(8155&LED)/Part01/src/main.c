#include "reg51.h"
#include "8155_func.h"

void main()
{
    C8155_init(0x0f);
    C8155_PC = 0x01;
    C8155_PB = 0x00;
}