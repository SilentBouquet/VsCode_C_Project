//do-while循环
//在进入循环时不做判断，执行完一轮循环体后再来检查条件是否满足
#include<stdio.h>
int main()
{
    int x;
    printf("请输入一个正整数：");
    scanf("%d",&x);
    int n = 0;
    do
    {
        x /= 10;
        n++;
    } while (x>0);
    printf("这是%d位数",n);
    return 0;
}