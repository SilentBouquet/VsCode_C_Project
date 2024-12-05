//if的嵌套语句
#include<stdio.h>
int main()
{
    int a,b,c,max;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b)
        if(a>c)
            max = a;
        else
            max = c;
    else
        if(b>c)
            max = b;
        else
            max = c;
    printf("最大的数为%d\n",max);
    return 0;
}
//if嵌套语句中，无大括号时，else总是与最近的那个if匹配，所以最好在if和else后面总是用{}