/*
什么是串？
1. 线性存储的一组数据(默认是字符)
2. 特殊操作集
求串的长度、比较两串是否相等、两串相接、求子串、插入子串、匹配子串、删除子串

串的模式匹配：
给定一段文本：string = s(0)s(1)...s(n-1)
给定一个模式：pattern = p(0)p(1)...p(m-1)
求pattern在string中出现的位置
Position PatternMatch(char *string, char *pattern)

简单实现：
1. C的库函数strstr
char *strstr(char *string, char *pattern)

#include <stdio.h>
#include <string.h>
#define NotFound NULL
typedef char* Position;
int main()
{
    char string[] = "This is a simple example.";
    char pattern[] = "simple";
    Position p = strstr(string, pattern);
    if ( p == NotFound ) printf("Not Found.\n");
    else printf("%s\n", p);
    return 0;
}
*/
#include <stdio.h>
#include <string.h>
#define NotFound NULL
typedef char* Position;
int main()
{
    char string[] = "This is a simple example.";
    char pattern[] = "sample";
    Position p = strstr(string, pattern);
    if ( p == NotFound ) printf("Not Found.\n");
    else printf("%s\n", p);
    return 0;
}