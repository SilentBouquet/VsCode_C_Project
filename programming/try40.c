//动态内存分配
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int number;
    int *a;
    int i;
    printf("输入数量：");
    scanf("%d\n", &number);
    //C99写法 int a[number];
    a = (int*)malloc(number*sizeof(int));
    //向malloc申请的空间大小是以字节为单位的
    //返回的类型是void*，需要类型转换成自己需要的类型
    //如果申请失败则返回0，或者叫NULL
    for (i=0; i<number; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i=number-1; i>=0; i--)
    {
        printf("%d", a[i]);
    }
    free(a);//归还申请来的空间;只能还申请来的空间的首地址
    return 0;
}