//字符串数组
//char **a：a是一个指针，指向另一个指针，那个指针指向一个字符或字符串
//char a[][]：a是一个二维数组变量，并且第二维一定要有确切的大小
//程序参数
//int main(int argc, char const *argv[])
//argv[0]是命令本身

#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i;
    for (i=0; i<argc; i++)
    {
        printf("%d:%s\n", i, argv[i]);
    }
    return 0;
}