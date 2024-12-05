#include <stdio.h>
int main()
{
    double f = 1234.56789;
    printf("%e,%f\n",f,f);
    double e = 1E-10;
    printf("%E,%.16f\n",e,e);
    printf("%.3f\n",-0.0049);
    printf("%.30f\n",-0.0049);
    printf("%.3f\n",-0.00049);
    return 0;
}