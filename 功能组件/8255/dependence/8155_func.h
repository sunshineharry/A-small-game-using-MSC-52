
#include "8155.H"

#define ReadPA() PA_8155
#define ReadPB() PB_8155
#define ReadPC() PC_8155
extern void Set8155(uchar command_2_8155);
extern void WritePA(uchar white_line);
extern void WritePB(uchar white_line);
extern void WritePC(uchar white_line);