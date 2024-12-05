//char* strcpy(char *restrict dst, const char *restrict src);
//把src的字符串拷贝到dst，并返回dst，restrict表明src和dst不重叠
#include <stdio.h>
#include <string.h>
//复制一个字符串:
//char *dst = (char*)malloc(strlen(src)+1);
//strcpy(dst, src);
#include <stdio.h>
#include <string.h>
char* mycpy(char* dst, const char* src)
{
    int idx = 0;
    while (src[idx])
    {
        dst[idx] = src[idx];
        idx++;
    }
    dst[idx] = '\0';
    return dst;
}

int main(int argc, char const *argv[])
{
    int i;
    char s1[] = "cba";
    char s2[] = "abc";
    strcpy(s1,s2);
    printf("%s", s1);
    return 0;
}