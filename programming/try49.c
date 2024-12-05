//字符串搜索函数
//在字符串里寻找某个字符第一次出现的位置；
//char* strchr(const char *s, int c);从左往右
//char* strrchr(const char *s, int c);从右往左
//返回NULL表示没有找到
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    char s[] = "hello";
    char *p = strchr(s, 'l');//查找第一个l
    char *q = strchr(p+1, 'l');//查找第二个l
    printf("%s\n", p);
    printf("%s\n", q);
    
    //将第一个l后面的字符串拷贝出来
    char *t = (char*)malloc(strlen(p)+1);
    strcpy(t, p);
    printf("%s\n", t);
    free(t);
    
    //输出第一个l前面的字符串
    char c = *p;
    *p = '\0';
    char *m = (char*)malloc(strlen(s)+1);
    strcpy(m, s);
    printf("%s\n", m);
    free(m);
    *p = c;//把字符串s回复原状
    printf("%s", s);
    return 0;
}
//字符串中找字符串
//char* strstr(const char *s1, const char *s2);
//char* strcasestr(const char *s1, const char *s2);
//第二个表示查找时不区分大小写