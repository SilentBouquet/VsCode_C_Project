//二维数组与遍历
#include<stdio.h>
int main()
{
    const int m = 4;
    const int n = 5;
    int a[m][n];
    int i,j;
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            a[i][j] = (i+1)*(j+1);
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}