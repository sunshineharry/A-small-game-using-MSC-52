#include "8155.H"

/**
 * @brief  设置8155的工作状态
 * @note   
 * @param  command_2_8155: 设置8155工作状态的参数
 * @retval None
 */
void Set8155(uchar command_2_8155)
{
    CMD_8155 = command_2_8155;
}

/**
 * @brief  将数据写入PA,PB,PC口
 * @note   
 * @param  white_line: 要写入的数据
 * @retval None
 */
void WritePA(uchar white_line)
{
    PA_8155 = white_line;
}

void WritePB(uchar white_line)
{
    PB_8155 = white_line;
}

void WritePC(uchar white_line)
{
    PC_8155 = white_line;
}


