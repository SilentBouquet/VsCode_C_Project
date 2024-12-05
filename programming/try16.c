#include<stdio.h>
int main()
{
    char c = 255;
    int i = 255;
    printf("c=%d,i=%d,c+1=%d\n",c,i,c+1);
    // 11111111
    // 00000000 00000000 00000000 11111111
    unsigned char a = 255;
    printf("a=%d\n",a);
    char m = -1;
    int n = -1;
    printf("m=%u,n=%u\n",m,n);
    return 0;
}