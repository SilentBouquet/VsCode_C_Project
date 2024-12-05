//结构类型
//和本地变量一样，在函数内部声明的结构类型只能在函数内部使用
//所以通常在函数外部声明结构类型
//声明结构的形式
/*
struct point{
    int x;
    int y;
};
struct point p1,p2;
p1,p2都是point，里面有x和y的值
或者
struct{
    int x;
    int y;
} p1, p2;
p1,p2都是一种无名结构，里面有x和y
或者
struct point{
    int x;
    int y;
} p1, p2;
p1,p2都是point里面有x和y的值
*/
//对于第一和第三种形式，都声明了结构point
//但第二种形式没有声明point，只是定义了两个变量

#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

int main(int argc, char const *argv[])
{
    struct date today;

    today.month = 03;
    today.day = 22;
    today.year = 2024;

    printf("Today's date is %i-%i-%i.\n",
        today.year, today.month, today.day);

    return 0;
}