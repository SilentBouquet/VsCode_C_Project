#include<stdio.h>
int main()
{
    int a = 6;
    printf("%ld\n",sizeof(a));//一个运算符，给出某个类型或变量在内存中所占据的字节数
    printf("%ld\n",sizeof(int));
    printf("%ld\n",sizeof(double));
    printf("%ld\n",sizeof(long double));
    printf("%ld\n",sizeof(char));
    printf("%ld\n",sizeof(short));
    printf("%ld\n",sizeof(long));
    printf("%ld\n",sizeof(long long));
    return 0;
//sizeof是静态运算符，结果在编译时刻就决定了，不会做运算
}