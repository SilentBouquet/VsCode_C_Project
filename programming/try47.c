//int strcmp(const char *s1, const char *s2);
//比较两个字符串，s1>s2时返回1，s1<s2时返回-1，s1等于s2时返回0
#include <stdio.h>
#include <string.h>
int mycmp(const char *s1, const char *s2)
{
    int idx = 0;
    while (s1[idx] == s2[idx] && s1[idx] != '\0')
    {
        idx++;
    }
    return s1[idx]-s2[idx];
}

int main(int argc, char const *argv[])
{
    char s1[] = "abc";
    char s2[] = "abc";
    char s3[] = "bbc";
    char s4[] = "Abc";
    printf("%d\n", strcmp(s1,s2));
    printf("%d\n", mycmp(s1,s2));
    printf("%d\n", strcmp(s1,s3));
    printf("%d\n", mycmp(s1,s3));
    printf("%d\n", strcmp(s1,s4));
    printf("%d\n", mycmp(s1,s4));
    printf("%d\n", 'a'-'A');
    return 0;
}