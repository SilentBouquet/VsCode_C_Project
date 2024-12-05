//for循环语句
//计算任意正整数的阶乘
#include<stdio.h>
int main()
{
    int n;
    printf("请输入一个正整数：");
    scanf("%d",&n);
    int fact = 1;
    for(int i=1;i<=n;i++){//第一个语句为初始化语句，只执行一次
    //第二句为条件判断，第三句为每次循环要执行的语句
    //每一个表达式都是可以省略的；for(;条件;) == while(条件)
        fact *= i;
    }
    printf("%d!=%d\n",n,fact);
    return 0;
}