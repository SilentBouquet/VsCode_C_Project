//链表
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node *next;
} Node;

typedef struct _list {
    Node *head;
} List;

void add(List* pList, int number);
void print(List *pList);

int main(int argc, char const *argv[])
{
    List list;
    int number;
    list.head = NULL;
    do {
        scanf("%d", &number);
        if ( number != -1 ) {
            add(&list, number);
        }
    } while ( number != -1);
    print(&list);//链表的输出
    scanf("%d", &number);
    Node *p;
    int isFound = 0;
    for ( p=list.head; p; p=p->next ) {
        if ( p->value == number ) {
            printf("找到了\n");
            isFound = 1;
            break;
        }
    }
    if ( !isFound ) {
        printf("没找到\n");
    }//链表的查询
    Node *q;
    for ( q=NULL, p=list.head; p; q=p, p=p->next ) {
        if ( p->value == number ) {
            if ( q ) {
                q->next = p->next;
            } else {
                list.head = p->next;
            }
            free(p);
            break;
        }
    }//链表的删除
    for ( p=list.head; p; p=q ) {
        q = p->next;
        free(p);
    }//链表的清除

    return 0;
}

void add(List* pList, int number)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    Node *last = pList->head;
    if ( last ) {
        while ( last->next ) {
            last = last->next;
        }
        last->next = p;
    } else {
        pList->head = p;
    }
}

void print(List *pList)
{
    Node *p;
    for ( p=pList->head; p; p= p->next){
        printf("%d\t", p->value);
    }
    printf("\n");
}