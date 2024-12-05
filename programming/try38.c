//除法运算
#include<stdio.h>
int divide(int a, int b, int *result)
{
    int ret = 1;
    if ( b == 0 ) ret = 0;
    else *result = a/b;
    return ret;
}

int main(void)
{
    int a;
    int b;
    int c;
    scanf("%d",&a);
    scanf("%d",&b);
    if ( divide(a,b,&c) )
    {
        printf("%d/%d=%d", a, b, c);
    }
    return 0;
}