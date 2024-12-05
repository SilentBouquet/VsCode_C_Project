//枚举
//枚举是一种用户定义的数据类型，用关键字enum来声明;
//enum 枚举类型名字{名字0,...,名字n};
//枚举类型名字通常并不真的使用，要用的是在大括号里的名字;
//因为它们就是常量符号，类型是int，值依次从0到n;
//当需要一些可排列起来的常量值时，定义枚举的意义就是给了这些常量值名字;
//枚举量可以作为值
//枚举类型可以跟上enum作为类型
//但实际上是以整数来做内部计算和外部输入输出的
#include <stdio.h>
enum color { red, yellow, green};

void f(enum color c);

int main(void)
{
    enum color t = red;
    scanf("%d", &t);
    f(t);
    return 0;
}

void f(enum color c)
{
    printf("%d\n", c);
}