//多重循环与goto
//凑数
#include<stdio.h>
int main()
{
    float x;
    int one, two, five;
    printf("请输入要凑的金额（元）：");
    scanf("%f",&x);
    for(one = 0; one <= x*10; one++){
        for(two = 0; two <= x*5; two++){
            for(five = 0; five <= x*2; five++){
                if(one + two*2 + five*5 == x*10){
                    printf("可以用%d个1角加%d个2角加%d个5角得到%f元\n",
                    one,two,five,x);
                    goto out;
                }
            }
        }
    }
    out:
    return 0;
}