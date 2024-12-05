//逃逸字符
//用来表达无法印出的控制字符或特殊字符，由一个反斜杠和另一个字符组成
#include <stdio.h>
int main()
{
    printf("123\b\n456\n");
    printf("123\bA\n456\n");
    printf("123abc\t456\n");
    printf("12\t456\n");
    return 0;
}
