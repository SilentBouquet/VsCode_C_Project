//数组
//求平均值，并输出大于平均值的数字
#include<stdio.h>
int main()
{
    int x;
    double sum =0;
    int cnt = 0;
    int number[100];//定义数组：<类型>变量名称[元素数量]
    scanf("%d",&x);
    while(x!=-1)
    {
        number[cnt] = x;
        sum += x;
        cnt ++;
        scanf("%d",&x);
    }
    if (cnt>0)
    {
        printf("%f\n",sum/cnt);
        int i;
        for (i=0;i<cnt;i++)
        {
            if (number[i]>sum/cnt)
            {
                printf("%d\n",number[i]);
            }
        }
    }
    return 0;
}