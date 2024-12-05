//求和函数
#include <stdio.h>
void sum(int begin, int end)
{
    int i;
    int sum = 0;
    for (i = begin;i <= end;i++)
    {
        sum = sum +i;
    }
    printf("从%d到%d的和是%d\n",begin,end,sum);
}
int main()
{
    sum(1,10);
    sum(20,30);
    sum(35,45);
    return 0;
}
//void是函数没有返回值，此时不能使用带值的return，调用时也不能做返回值的赋值
//函数头以分号结尾，就构成了函数的原型，目的是告诉编译器这个函数长什么样子