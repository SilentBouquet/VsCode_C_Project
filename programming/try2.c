//输入scanf的使用
#include<stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d",&a,&b);  //输入时保证格式仍然为%d,%d，否则会读不到
    printf("%d %d\n", a, b);
    printf("%d + %d = %d\n",a,b,a+b);
    return 0;
}