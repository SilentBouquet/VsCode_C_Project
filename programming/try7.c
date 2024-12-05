//级联的if-else语句
#include<stdio.h>
int main()
{
    int x,f;
    scanf("%d",&x);
    if(x<0)
    {
        f = -x;
    }
    else if(x == 0)
    {
        f = 0;
    }
    else if(x<10&x>0)
    {
        f = x*x;
    }
    else
    {
        f = 2*x+80;
    }
    printf("%d\n",f);
    return 0;
}