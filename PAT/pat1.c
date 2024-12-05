// 害死人不偿命的(3n+1)猜想
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    double  m = log2((double)n);
    if ( ceil(m) == floor(m) )
        printf("%d", (int)m);
    else {
        int count = 0;
        while ( n != 1 ) {
            if ( n % 2 == 0 )
                n = n / 2;
            else 
                n = (3 * n + 1) / 2;
            count++;
        }
        printf("%d", count);
    }
    
    return 0;
}