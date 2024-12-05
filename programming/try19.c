//浮点类型
#include <stdio.h>
int main()
{
    printf("%f\n",12.0/0.0);
    printf("%f\n",-12.0/0.0);
    printf("%f\n",0.0/0.0);
    float a,b,c;
    a = 1.345f;
    b = 1.123f;
    c = a + b;
    if (c == 2.468)
        printf("相等\n");
    else
        printf("不相等!c=%.10f,或%f\n",c,c);
    return 0;
}