//最大子列求和问题
//算法1
#include <stdio.h>
int MaxSubseqSum1( int A[], int N )
{
    
    int ThisSum, MaxSum = 0;
    int i, j, k;
    for ( i = 0; i < N; i++ )
    {
       for ( j = i; j < N; j++ )
       {
            int ThisSum = 0;
            for ( k = i; k <= j; k++ )
                ThisSum += A[k];
            if ( ThisSum > MaxSum )
                MaxSum = ThisSum;
       }
    }
    return MaxSum;
    /*该算法复杂度为T(N)=O(N^3)*/
}
//算法2
int MaxSubseqSum2( int A[], int N )
{
    int ThisSum, MaxSum = 0;
    int i, j;
    for ( i = 0; i < N; i++ )
    {
        ThisSum = 0;
        for ( j = i; j < N; j++ )
        {
            ThisSum += A[j];
            if ( ThisSum > MaxSum )
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
    /*该算法复杂度为T(N)=O(N^2)*/
}
//算法3：分而治之；复杂度为T(N)=O(NlogN)
//算法4：在线处理
int MaxSubseqSum4( int A[], int N )
{
    int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for ( i = 0; i < N; i++ )
    {
        ThisSum += A[i];
        if ( ThisSum > MaxSum )
            MaxSum = ThisSum;
        else if ( ThisSum < 0 )
            ThisSum = 0;
    }
    return MaxSum;
    /*该算法复杂度为T(N)=O(N)*/
}
int main()
{
    int A[10] = {1, 3, -2, 5, 3, -8, 1, -4, -5, 9};
    printf("%d\n", MaxSubseqSum1( A, 10 ));
    printf("%d\n", MaxSubseqSum2( A, 10 ));
    printf("%d\n", MaxSubseqSum4( A, 10 ));
}