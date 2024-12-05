//拯救007
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct node {
    int x, y;
} p[110];
int vis[110];
int flag = 0;
int n, m;

int DFS( int t );
int IsSafe( int x );
int FirstJump( int x );
int Jump( int x, int y );

int main()
{
    memset(vis, 0, sizeof(vis));
    scanf("%d %d", &n, &m);
    int i;
    for( i=0; i<n; i++ )
    {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    if( m >= 42.5 )
    {
        printf("Yes\n");
    }
    else
    {
        for( i=0; i<n; i++ )
        {
            if( !vis[i] && FirstJump(i) )
            {
                DFS(i);
            }
        }
        if( flag == 1 )
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

int DFS( int t )
{
    vis[t] = 1;
    if ( IsSafe(t) == 1 ) flag = 1;
    for ( int i=0; i<n; i++ )
        if ( !vis[i] && Jump(t, i) ) {
            flag = DFS(i);
            if (flag == 1)
                break;
    } 
    return flag;
}

int IsSafe( int x )
{
    if ((p[x].x - m <= -50)||(p[x].x + m >= 50)||(p[x].y - m <= -50)||(p[x].y + m >= 50))
        return 1;
    return 0;
}

int FirstJump( int x )
{
    int p1 = pow(p[x].x, 2);
    int p2 = pow(p[x].y, 2);
    int r = pow(m+7.5, 2);
    if (p1+p2<=r)
        return 1;
    return 0;
}

int Jump( int x, int y )
{
    int p1 = pow(p[x].x - p[y].x,2);
    int p2 = pow(p[x].y - p[y].y,2);
    int r = m*m;
    if(p1+p2<=r)
        return 1;
    return 0;
}