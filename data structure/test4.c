//多项式乘法与加法运算
#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode {
    int coef;
    int expon;
    Polynomial link;
};
Polynomial P1,P2;
Polynomial ReadPoly();
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial P);
void Attach(int c, int e, Polynomial *pRear);
int compare(int a, int b);

int main()
{
    Polynomial P1, P2, PP, PS;

    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = Mult(P1,P2);
    PrintPoly(PP);
    PS = Add(P1,P2);
    PrintPoly(PS);

    return 0;
}

Polynomial ReadPoly()
{
    Polynomial P, Rear, t;
    int N, c, e;

    scanf("%d", &N);
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while (N--) {
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear);
    }
    t = P; P = P->link;
    free(t);

    return P;
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
    Polynomial front, rear, temp;
    int sum;
    rear = (Polynomial)malloc(sizeof(struct PolyNode));
    front = rear;
    while (P1 && P2) {
        switch (compare(P1->expon, P2->expon)) {
        case 1:
            Attach(P1->coef, P2->expon, &rear);
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
    for ( ;P1;P1 = P1->link )
        Attach(P1->coef, P1->expon, &rear);
    for ( ;P2;P2 = P2->link )
        Attach(P2->coef, P2->expon, &rear);
    rear->link = NULL;
    temp = front;
    front = front->link;
    free(temp);
    return front;
}

/*
如何将两个多项式相乘
方法：
1.将乘法运算转换为加法运算
将P1当前项(ci,ei)乘P2多项式，再加到结果多项式里
t1 = P1; t2 = P2;
P = (Polynomial)malloc(sizeof(struct PolyNode));
P->link = NULL;
Rear = P;
while (t2) {
    Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
    t2 = t2->link;
}
2.逐项插入
将P1当前项(c1i,e1i)乘P2当前项(c2i,e2i)并插入到结果多项式中，关键是要找到插入位置
初始结果多项式可由P1第一项乘P2获得
*/

Polynomial Mult(Polynomial P1, Polynomial P2)
{
    Polynomial t1, t2, t, Rear, P;
    int e, c;

    if (!P1||!P2) return NULL;

    t1 = P1; t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while (t2) {
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while (t1) {
        t2 = P2; Rear = P;
        while (t2) {
            e = t1->expon + t2->expon;
            c = t1->coef*t2->coef;
            while (Rear->link&&Rear->link->expon>e)
                Rear = Rear->link;
            if (Rear->link&&Rear->link->expon==e) {
                if (Rear->link->coef+c)
                    Rear->link->coef+=c;
                else {
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            } else {
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = P; P = P->link;
    free(t2);

    return P;
}

void PrintPoly(Polynomial P)
{
    int flag = 0;

    if (!P) {
        printf("0 0\n");
        return;
    }

    while (P) {
        if (!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}

void Attach(int c, int e, Polynomial *pRear)
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