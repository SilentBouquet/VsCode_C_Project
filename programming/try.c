//++a与a++的区别
#include<stdio.h>
int main()
{
    int a;
    a = 10;
    printf("a++=%d\n", a++);
    printf("a=%d\n", a);
    printf("++a=%d\n", ++a);
    printf("a=%d\n", a);
    return 0;
}