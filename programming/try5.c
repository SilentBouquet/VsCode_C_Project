//if语句的使用(有else子句部分)
#include<stdio.h>
int main()
{
    int price;
    int bill;
    printf("请输入金额：");
    scanf("%d",&price);
    printf("请输入票面：");
    scanf("%d",&bill);
    if(bill>=price)
    {
        printf("应该找您:%d\n",bill-price);
    }
    else
    {
        printf("你的钱不够\n");
    }
    return 0;
}
//if和else后面可以没有大括号，此时只包含下一个语句