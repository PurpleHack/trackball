# 轨迹球驱动

轨迹球模拟鼠标驱动程序，适用于小型掌机/PC设备，支持系统 macos, windows, linux。

![preview](/assets/preview.gif)


## 硬件

- promicro mega32u4 开发板
  
  ![promicro](/assets/promicro.avif)
- 轨迹球模块
  
  ![trackball](/assets/trackball.avif)

## 注意事项

项目使用 vscode plateform 开发。
根据实际焊接更改代码引脚定义

```c
const int upButton = 3;
const int downButton = 4;
const int leftButton = 5;
const int rightButton = 6;
const int centerButton = 7;
```