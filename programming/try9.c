//while语句
//判断输入整数的位数
#include<stdio.h>
int main()
{
    int x;
    int n = 0;
    printf("请输入一个正整数：");
    scanf("%d",&x);
    while(x>0)
    {
        n++;
        x/=10;
    }
    printf("这是%d位数",n);
    return 0;
}
//判断0时会得出这是0位数