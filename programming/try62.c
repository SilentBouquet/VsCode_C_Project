//宏定义
//#开头的是编译预处理指令
//它们不是C语言的成分，但是C语言程序离不开它们
//#define用来定义一个宏
//#define <名字> <值>
//注意没有结尾的分号，因为不是C的语句
//名字必须是一个单词，值可以是各种东西
//在C语言的编译器开始编译之前，编译预处理程序会把程序中的名字换成值
//如果一个宏的值中有其他宏的名字，也是会被替换的
//如果一个宏的值超过一行，最后一行之前的行末需要加\
//宏的值后面出现的注释不会被当作宏的值的一部分
//存在没有值的宏，如：#define _DEBUG
//这类宏是用于条件编译的，后面有其他的编译预处理指令来检查这个宏是否已经被定义过了
//预定义的宏：
/*
__LINE__：源代码当前所在位置的行号
__FILE__：源代码文件的文件名
__DATE__：编译时候的日期
__TIME__：编译时候的时间
__STDC__：当编译器以ANSI标准编译时，则定义为1；判断该文件是不是标准C程序
*/
#include <stdio.h>
#define PI 3.14159
#define FORMAT "%f\n"
#define PI2 2*PI // pi*2
#define PRT printf("%f\n", PI); \
            printf("%f\n", PI2)

int main(int argc, char const *argv[])
{
    printf("%f\n", 2*PI*3.0);
    printf("%f\n", PI2*3.0);
    printf(FORMAT, PI2*3.0);
    PRT;
    printf("%s:%d\n", __FILE__, __LINE__);
    printf("%s,%s\n", __DATE__, __TIME__);
    return 0;
}