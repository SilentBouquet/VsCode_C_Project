#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    void *p;
    int cnt = 0;
    while ( (p=malloc(1000*1024*1024)) )
    {
        cnt++;
    }
    printf("分配了%d000MB的空间\n", cnt);
    free(p);
    return 0;
}