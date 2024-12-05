//字符类型
//char是一种整数，也是一种特殊的类型，用单引号表示字符字面量
//''也是一个字符
//printf和scanf里用%c来输入输出字符
#include <stdio.h>
int main()
{
    char c,d;
    c = 1;
    d = '1';
    if ( c == d )
    {
        printf("相等\n");
    }
    else
    {
        printf("不相等\n");
    }
    printf("c=%d\n",c);
    printf("d=%d\n",d);
    return 0;
}