//if语句的使用(无else)
#include<stdio.h>
int main()
{
    float a,b;
    scanf("%f,%f",&a,&b);
    if(a>b)
    {
        printf("%.2f,%.2f\n",a,b);
    }
    if(a<=b)
    {
        printf("%.2f,%.2f\n",b,a);
    }
    return 0;
}
//关系运算符的优先级比算术运算的低，但比赋值运算的高
//判断是否相等的优先级比其他的低，而连续的关系运算是从左到右进行的