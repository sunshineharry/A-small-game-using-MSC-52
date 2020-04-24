# MCS52 单片机打地鼠游戏

![Keil C51](https://l-tek.si/wp-content/uploads/2017/08/Keil-logo-300x143.jpg)

## 项目简介
用51单片机实现模拟打地鼠小游戏，灯亮表示地鼠探头，你需要在半秒内按下旁边的按钮，表示把地鼠打回去，这样你可以赢得一分，如果连续三次没有将地鼠打回去，则游戏失败，你只能重新开始。

本游戏提供暂停和继续功能。

![output](https://github.com/sunshineharry/A-small-game-using-MSC-52/blob/master/%E6%89%93%E5%9C%B0%E9%BC%A0%E6%B8%B8%E6%88%8F/documents/output2.gif?raw=true)

## 文件说明
- `proteus`文件夹中为proteus仿真
  
- `code`文件夹中为源代码
  
    - `src`目录为所有的`.c`文件
  
    - `dependence`目录为所有的`.h`文件
  
    - 其他目录都为中间文件或配置文件

## 函数命名
- 以  `_` 开头的函数表示只在所在文件当中起作用，不对外展现接口，例如`_LCD_delay()`只在`LCD.C`中被调用；
  
- 硬件的接口函数的命名规则`硬件名(大写)_函数名`,提供提供接口，在`_func.c`中进行声明，如`LCD_clear()`表示LCD屏幕的清空，在`LCD_func.h`中声明


