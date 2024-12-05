//带参数的宏
//定义时一切都要带括号
//整个值要括号，参数出现的每个地方都要括号
//可以带多个参数
//#define MIN(a,b) ((a)>(b)?(b):(a))
//也可以组合（嵌套）使用其他宏
#include <stdio.h>

#define cube(x) ((x)*(x)*(x))

int main(int argc, char const *argv[])
{
    int i;
    scanf("%d", &i);
    printf("%d\n", cube(5));
    printf("%d\n", cube(i));

    return 0;
}