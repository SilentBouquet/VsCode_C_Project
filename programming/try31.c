//判断素数(2)
#include<stdio.h>
int isprime(int x, int knownprimes[], int numberofknownprimes)
{
    int ret = 1;
    int i;
    for (i=0;i<numberofknownprimes;i++)
    {
        if (x%knownprimes[i]==0)
        {
            ret = 0;
            break;
        }
    }
    return ret;
}
int main(void)
{
    const int number = 10;
    int prime[number];
    prime[0] = 2;
    int count = 1;
    int i =3;
    while (count<number)
    {
        if (isprime(i,prime,count)==1)
        {
            prime[count++] = i;
        }
        {
            printf("i=%d\tcnt=%d\t",i,count);
            int i;
            for (i=0;i<count;i++)
                {
                    printf("%d\t",prime[i]);
                }
                printf("\n");
        }
        i++;
    }
    for (i=0;i<number;i++)
    {
        printf("%d",prime[i]);
        if ((i+1)%5==0)
        {
            printf("\n");
        }
        else
        {
            printf("\t");
        }
    }
    return 0;
}