//循环控制：break与continue
//判断素数
#include<stdio.h>
int main()
{
    int x;
    printf("请输入一个正整数：");
    scanf("%d",&x);
    int i;
    int isprime = 1;
    for(i=2;i<=x;i++){
        if(x % i == 0){
            isprime = 0;
            break;//跳出整个for循环
        //continue则是跳过循环这一轮剩下的语句进入下一轮
        }
    }
    if(isprime == 1){
        printf("是素数\n");
    }else{
        printf("不是素数\n");
    }
    return 0;
}