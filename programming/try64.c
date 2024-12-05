//格式化的输入输出
//printf：%[flags][width][.prec][hlL]type
//flags(标志)：
/*
-：左对齐
+：在前面放+或-
(space)：正数留空
0：0填充
*/
//width或prec(宽度)：
/*
number：最小字符数
*：下一个参数是字符数
.number：小数点后的位数
.*：下一个参数是小数点后的位数
*/
//hlL(类型修饰)：
/*
hh：单个字节(char)
h：short
l：long
ll：long long
L：long double
*/
//scanf：%[flag]type
//flag：
/*
*：跳过
数字：最大字符数
hh：单个字节(char)
h：short
l：long
ll：long long
L：long double
*/
//type：
/*
i：整数，可能为十六进制或八进制
o：八进制
x：十六进制
[...]：所允许的字符
*/
//prinf和scanf有返回值，分别是读入的项目数和输出的字符数

#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%9d\n", 123);
    printf("%-9d\n", 123);
    printf("%+9d\n", 123);
    printf("%09d\n", 123);

    printf("%9.2f\n", 123.0);
    printf("%*d\n", 6, 123);

    printf("%hhd\n", (char)12345);

    int num;
    //scanf("%*d%d", &num);
    //printf("%d\n", num);
    int a;
    scanf("%i", &a);
    printf("%d\n", a);

    int b;
    int i1 = scanf("%i", &b);
    int i2 = printf("%d\n", b);
    printf("%d:%d\n", i1, i2);

    return 0;
}