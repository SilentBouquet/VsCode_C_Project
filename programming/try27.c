//从函数中返回值
#include <stdio.h>
int max(int a, int b)
{
    int ret;
    if (a>b)
    {
        ret = a;
    }
    else
    {
        ret = b;
    }
    return ret;
}
int main()
{
    int a,b,c;
    a = 10;
    b = 12;
    c = max(a,b);
    printf("%d",c);
    return 0;
}
//return停止函数的执行，并返回一个值；一个程序可以有多个return