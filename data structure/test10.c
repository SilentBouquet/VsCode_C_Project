//Complete Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MaxSize 100

int A[MaxSize], T[MaxSize];

int min_( int a, int b )
{
    return a < b ? a : b;
}

int GetLeftLength( int n )
{
    int H = floor(log2(n+1));
    int X = n + 1 - pow(2, H);
    int L = pow(2, (H - 1)) - 1 + min_(X, pow(2, (H-1)));
    return L;
}

void solve(int aleft,int aright,int root)
{
    int n = aright - aleft + 1;
    if ( n == 0 ) return;
    int L = GetLeftLength(n);
    T[root] = A[aleft+L];
    int leftroot = 2 * root + 1;
    int rightroot = leftroot + 1;
    solve(aleft, aleft+L-1, leftroot);
    solve(aleft+L+1, aright, rightroot);
}

int compare(const void*a, const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n, r;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &r);
        A[i] = r;
    }
    printf("输入数组为：");
    for (int i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    qsort(A, n, sizeof(int), compare);
    printf("排序后数组为：");
    for (int i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    solve(0, n-1, 0);
    printf("完全二叉搜索树的层序遍历的数组为：");
    for (int i=0; i<n; i++) {
        printf("%d ", T[i]);
    }
    return 0;
}