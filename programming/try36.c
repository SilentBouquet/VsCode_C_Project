//指针的应用
//交换两个变量的值(函数无法做到)
#include<stdio.h>
void swap(int *pa, int *pb);
int main(void)
{
    int a = 5;
    int b = 6;
    swap(&a,&b);
    printf("a=%d,b=%d\n",a,b);
    return 0;
}
void swap(int *pa, int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
}