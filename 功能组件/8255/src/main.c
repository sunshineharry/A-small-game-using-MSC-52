#include "reg52.h"
#include "8155_func.h"

void main()
{
    Set8155(0x01);
    WritePA(0x02);
	while(1);
}