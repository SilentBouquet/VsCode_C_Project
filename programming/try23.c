//自动类型转换
//当运算符的两边出现不一致的类型时，会自动转换成较大的类型
//char——short——int——long——long long(整数)
//int——float——double(整数和浮点数)
//对于printf，任何小于int的类型会被转换成int；float会被转换成double
//但是scanf不会，要输入short，需要%hd
//要把一个量强制转换成另一个类型（通常是更小的类型），需要：(类型)值;
#include <stdio.h>
int main()
{
    printf("%d\n",(short)32768);
    int i = 32768;
    short s = (short)i;
    printf("%d\n",i);
    int a = 5;
    int b = 6;
    double m = (double)a/b;
    double n = (double)(a/b);
    printf("m=%f\nn=%f",m,n);
    //强制类型转换的优先级高于四则运算
    return 0;
}