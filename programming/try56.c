//结构数组
#include <stdio.h>

struct time {
    int hour;
    int minutes;
    int seconds;
};

struct time timeUpdate(struct time now);

int main(void)
{
    struct time testTimes[5] = {
        {11,59,59}, {12,0,0}, {1,29,59}, {23,59,59}, {19,12,27}
    };
    int i;

    for ( i=0; i<5; ++i ) {
        printf("Time is %.2i:%.2i:%.2i",
            testTimes[i].hour, testTimes[i].minutes, testTimes[i].seconds);
        
        testTimes[i] = timeUpdate(testTimes[i]);

        printf(" ...one second later it's %.2i:%.2i:%.2i\n",
            testTimes[i].hour, testTimes[i].minutes, testTimes[i].seconds);
    }

    return 0;
}

struct time timeUpdate(struct time now)
{
    ++now.seconds;
    if ( now.seconds == 60 ) {
        now.seconds = 0;
        ++now.minutes;

        if ( now.minutes == 60 ) {
            now.minutes = 0;
            ++now.hour;

            if ( now.hour == 24 ) {
                now.hour = 0;
            }
        }
    }
    return now;
}

//嵌套的结构
/*
struct point {
    int x;
    int y;
};
struct rectangle {
    struct point pt1;
    struct point pt2;
};

如果有变量
    struct rectangle r;
就可以有：
    r.pt1.x, r.pt1.y,
    r.pt2.x, r.pt2.y

如果有变量定义：
    struct rectangle r, *rp;
    rp = &r;
那么下面的四种形式是等价的：
    r.ptl.x
    rp->pt1.x
    (r.pt1).x
    (rp->pt1).x
但是没有rp->pt1->x(因为pt1不是指针)
*/