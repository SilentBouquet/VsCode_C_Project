//自定义数据类型(typedef)
#include <stdio.h>

int main(void)
{
    typedef long int64_t;
    typedef struct ADate {
        int month;
        int day;
        int year;
    } Date;//Date等价于struct ADate

    int64_t i = 1000000000;
    Date d = {9, 1, 2005};

    typedef int Length;//Length就等价于int类型

    typedef char* Strings[10];//Strings是10个字符串的数组的类型

    return 0;
}