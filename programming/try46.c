//字符串函数
//size_t strlen(const char *s);
#include <stdio.h>
#include <string.h>
size_t mylen(const char *s)
{
    int idx = 0;
    while (s[idx] != '\0')
    {
        idx++;
    }
    return idx;
}

int main(int argc, char const *argv[])
{
    char line[] = "Hello";
    printf("strlen=%lu\n", strlen(line));//返回s的字符串长度，不包括结尾的0
    printf("mylen=%lu\n", mylen(line));
    printf("strlen=%lu\n", sizeof(line));
}