//全局变量
//定义在函数外面的变量是全局变量
//全局变量具有全局的生存期和作用域
//它们与任何函数都无关，在任何函数内部都可以使用它们
#include <stdio.h>

int f(void);

int gAll = 12;

int main(int argc, char const *argv[])
{
    printf("in %s gAll=%d\n", __func__, gAll);
    f();
    printf("agn in %s gAll=%d\n", __func__, gAll);

    return 0;
}

int f(void)
{
    printf("in %s gAll=%d\n", __func__, gAll);
    gAll += 2;
    printf("agn in %s gAll=%d\n", __func__, gAll);
    return gAll;
}
//全局变量初始化
//没有做初始化的全局变量会得到0值，指针会得到NULL值
//只能用编译时刻已知的值来初始化全局变量
//它们的初始化发生在main函数之前
//如果函数内部存在与全局变量同名的变量，则全局变量会被隐藏