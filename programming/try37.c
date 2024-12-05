//求最大与最小值
#include<stdio.h>
void minmax(int *a, int len, int *max, int *min)
{
    int i;
    printf("sizeof(a)=%lu\n", sizeof(a));
    *min = *max = a[0];
    for (i=1;i<len;i++)
    {
        if (a[i]<*min) 
        {
            *min = a[i];
        }
        if (a[i]>*max) 
        {
            *max = a[i];
        }
    }
}

int main()
{
    const int number = 10;
    int a[number];
    int i;
    for ( i=0; i<number; i++)
    {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    int min,max;
    printf("sizeof(a)=%lu\n", sizeof(a));
    minmax(a,sizeof(a)/sizeof(a[0]),&max,&min);
    printf("max=%d,min=%d", max, min);
    return 0;
}
/*数组变量是特殊的指针
数组变量本身表达地址，无需用&取地址
但是数组的单元表示的是变量，需要用&取地址
[]与*运算符可以对数组做，也可以对指针做
数组变量是const的指针，所以不能被赋值*/