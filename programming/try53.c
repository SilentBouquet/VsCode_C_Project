//结构的初始化
#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

int main(int argc, char const *argv[])
{
    struct date today = {03,23,2024};
    struct date thismonth = {.month=3, .year=2024};

    printf("Today's date is %i-%i-%i.\n",
        today.year,today.month,today.day);
    printf("This month is %i-%i-%i.\n",
        thismonth.year,thismonth.month,thismonth.day);

    struct date today1;

    today1 = (struct date){03,23,2024};

    struct date thismonth1;

    thismonth1 = today1;
    thismonth1.day = 22;

    printf("Today's date is %i-%i-%i.\n",
        today1.year,today1.month,today1.day);
    printf("This month is %i-%i-%i.\n",
        thismonth1.year,thismonth1.month,thismonth1.day);

    return 0;
}
//结构和数组有点像
//数组用[]运算符和下标访问其成员
//结构用.运算符和名字访问其成员
//要访问整个结构，直接用结构变量的名字
//对于整个结构，可以做赋值，取地址，也可以传递给函数参数
//和数组不同，结构变量的名字并不是结构变量的地址，必须使用&运算符
//struct date *pDate = &today;