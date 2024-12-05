//自动计数的枚举
#include <stdio.h>

enum COLOR {RED, YELLOW, GREEN, NumCOLORS};

int main(int argc, char const *argv[])
{
    int color = -1;
    char* ColorNames[NumCOLORS] = {
        "red", "yellow" ,"green",
    };
    char *colorName = NULL;

    printf("输入你喜欢打的颜色代码：");
    scanf("%d", &color);
    if ( color >=0 && color < NumCOLORS )
    {
        colorName = ColorNames[color];
    }
    else
    {
        colorName = "unknown";
    }
    printf("你喜欢的颜色是%s\n", colorName);

    return 0;
}
//声明枚举量的时候可以指定值
//enum COLOR {RED=1, YELLOW, GREEN=5}; 