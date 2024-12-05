//switch-case语句
#include<stdio.h>
int main()
{
    int type;
    scanf("%d",&type);
    switch (type)//控制表达式只能是整数型结果
    {
    case 1:
        printf("你好");
        break;//没有break则顺序执行到下一个case里去，直到遇到break或者switch结束为止
    case 2:
        printf("早上好");
        break;
    case 3:
        printf("晚上好");
        break;
    case 4:
        printf("再见");
        break;
    default:
        printf("啊，什么啊？");
        break;
    } 
    return 0;
}