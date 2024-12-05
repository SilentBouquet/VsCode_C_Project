//整数与浮点数
#include<stdio.h>
int main()
{
    printf("%d\n",10/3);
    printf("%f\n",10.0/3);
//整数与整数的运算结果只能是整数，而当浮点数与整数放到一起运算时，C会将整数转换成浮点数，然后进行浮点数的运算，结果为浮点数。  

//英尺与米的换算
    double m;
    double n;
    scanf("%lf %lf", &m, &n);
    printf("%f\n",((m + n/12)*0.3048));
    return 0;
}