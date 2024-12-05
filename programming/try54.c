//结构与函数
//整个结构可以作为参数的值传入函数，也可以返回一个结构
//这时候是在函数内新建一个结构变量，并复制调用者的结构的值
#include <stdio.h>
#include <stdbool.h>

struct date {
    int year;
    int month;
    int day;
};

bool isLeap(struct date d);
int numberofDays(struct date d);

int main(int argc, char const *argv[])
{
    struct date today, tomorrow;

    printf("Enter today's date (yyyy mm dd):");
    scanf("%i %i %i", &today.year, &today.month, &today.day);

    if (today.day != numberofDays(today)) {
        tomorrow.day = today.day+1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    } else if (today.month == 12) {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year+1;
    } else {
        tomorrow.day = 1;
        tomorrow.month = today.month+1;
        tomorrow.year = today.year;  
    }

    printf("Tomorrow's date is %i-%i-%i.\n",
        tomorrow.year, tomorrow.month, tomorrow.day);
    
    return 0;
}

int numberofDays(struct date d)
{
    int days;

    const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d.month ==2&& isLeap(d))
        days = 29;
    else
        days = daysPerMonth[d.month-1];
    
    return days;
}

bool isLeap(struct date d)
{
    bool leap = false;

    if ((d.year %4 ==0 && d.year %100 !=0) || d.year%400 ==0)
        leap = true;
    
    return leap;
}