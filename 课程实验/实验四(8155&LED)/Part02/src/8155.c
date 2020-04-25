#include "8155.H"

/**
 * @brief  设置8155的工作状态
 * @note   
 * @param  command_2_8155: 设置8155工作状态的参数
 * @retval None
 */
void C8155_init(uchar command_2_8155)
{
    C8155_CMD = command_2_8155;
}



