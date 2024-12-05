//多项式加法运算
//主要思路：相同指数的项系数相加，其余部分进行拷贝
//采用不带头结点的单向链表，按照指数递减的顺序排列各项
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PolyNode {
    int coef;
    int expon;
    struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;
Polynomial P1,P2;
void Attach( int c, int e, Polynomial *pRear );
int compare(int a, int b);

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
    Polynomial front, rear, temp;
    int sum;
    rear = (Polynomial)malloc(sizeof(struct PolyNode));
    front = rear;   //由front记录结果多项式链表头结点
    while (P1 && P2) {  //当两个多项式都有非零项待处理时
        switch (compare(P1->expon, P2->expon)) {
        case 1:
            Attach(P1->coef, P2->coef, &rear);
            P1 = P1->link;
            break;
        case -1:
            Attach(P2->coef, P2->expon, &rear);
            P2 = P2->link;
            break;
        case 0:
            sum = P1->coef + P2->coef;
            if (sum) Attach(sum, P1->expon, &rear);
            P1 = P1->link;
            P2 = P2->link;
            break;
        }
    }
    //将未处理完的另一个多项式的所有节点依次复制到结果多项式中去
    for ( P1;P1 = P1->link; )
        Attach(P1->coef, P1->expon, &rear);
    for ( P2;P2 = P2->link; )
        Attach(P2->coef, P2->expon, &rear);
    rear->link = NULL;
    temp = front;
    front = front->link;    //令front指向结果多项式第一个非零项
    free(temp);     //释放临时空表头结点
    return front;
}

void Attach( int c, int e, Polynomial *pRear )
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;
}

int compare(int a, int b)
{
    if ( a>b )
        return 1;
    else if ( a<b )
        return -1;
    else
        return 0;
}