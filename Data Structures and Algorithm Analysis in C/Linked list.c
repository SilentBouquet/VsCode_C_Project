//链表的实现
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node;  //存储数据的节点
typedef struct Node *PtrToNode; //指向下个节点的指针
typedef PtrToNode List; //表头用List表示，存储的数据默认为链表的长度（不包含表头）
typedef PtrToNode Position; //存储数据的节点用Position表示
typedef int ElementType;  //抽象一个数据类型，暂时定为int

void MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(ElementType X, List L);
void ShowList(List L);
ElementType FindFirst(List L);
ElementType FindLast(List L);
int FindIndex(ElementType X, List L);
Position FindElement(int pos, List L);
int FindPreIndex(ElementType X, List L);
void DeleteFirst(List L);
void DeleteLast(List L);
void DeleteElement(ElementType X, List L);
void DeleteIndex(int pos, List L);
void Push_front(ElementType X, List L);
void Push_back(ElementType X, List L);
void Insert(ElementType X, int pos, List L);
void SortList(List L, bool ASC);
ElementType Length(List L);
void DeleteList(List L);

//定义结构体，其中包含一个存储的数据和指向下一个节点的指针
struct Node
{
    ElementType Element;
    Position Next;
};

int main()
{
    List L = (List)malloc(sizeof(struct Node));

    while (1) {
        printf("链表操作：\n");
        printf("1.  创造一个空链表\n");
        printf("2.  检查链表是否为空\n");
        printf("3.  检查元素是否为最后一个\n");
        printf("4.  打印当前链表\n");
        printf("5.  查找第一个元素\n");
        printf("6.  查找最后一个元素\n");
        printf("7.  查找指定元素的位置\n");
        printf("8.  查找指定位置的元素\n");
        printf("9.  删除第一个元素\n");
        printf("10. 删除最后一个元素\n");
        printf("11. 删除指定元素\n");
        printf("12. 删除指定位置的元素\n");
        printf("13. 在头部插入元素\n");
        printf("14. 在尾部插入元素\n");
        printf("15. 在指定位置插入元素\n");
        printf("16. 为当前链表进行排序\n");
        printf("17. 查看当前链表的长度\n");
        printf("18. 删除当前链表\n");
        printf("q.  退出程序\n");

        int ret, X, pos;
        char Choice[100] = "";
        char choice;
        printf("请选择要进行的操作：");
        scanf("%s", Choice);
        if (!strcmp(Choice, "q")) {
            printf("是否退出程序？(y/n)：");
            getchar();
            scanf("%c", &choice);
            if (choice == 'y') {
                printf("欢迎下次使用~\n");
                system("pause");
                break;
            } else if (choice != 'n') {
                printf("输入有误，请重新输入！\n");
            }
        }
        else if (!strcmp(Choice, "1")) {
            MakeEmpty(L);
            printf("创建成功！\n");
        }
        else if (!strcmp(Choice, "2")) {
            ret = IsEmpty(L);
            if (ret) {
                printf("当前链表为空\n");
            } else {
                printf("当前链表不为空\n");
            }
        }
        else if (!strcmp(Choice, "3")) {
            printf("请输入要查询的元素：");
            scanf("%d", &X);
            ret = IsLast(X, L);
            if (ret == -1) {}
            else if (ret == 1) {
                printf("该元素是当前链表的最后一位\n");
            } else {
                printf("该元素不是当前链表的最后一位\n");
            }
        }
        else if (!strcmp(Choice, "4")) {
            ShowList(L);
        }
        else if (!strcmp(Choice, "5")) {
            if (FindFirst(L) != -1)
                printf("当前链表的第一个元素为%d\n", FindFirst(L));
        }
        else if (!strcmp(Choice, "6")) {
            if (FindLast(L) != -1)
                printf("当前链表的最后一个元素为%d\n", FindLast(L));
        }
        else if (!strcmp(Choice, "7")) {
            printf("请输入要查询的元素：");
            scanf("%d", &X);
            pos = FindIndex(X, L);
            if (pos != -1) {
                printf("该元素在当前链表的第%d位\n", pos);
            }
        }
        else if (!strcmp(Choice, "8")) {
            printf("请输入要查询的位置：");
            scanf("%d", &pos);
            Position P = FindElement(pos, L);
            if (P != NULL) {
                printf("当前链表的第%d位为%d\n", pos, P->Element);
            }
        }
        else if (!strcmp(Choice, "9")) {
            DeleteFirst(L);
        }
        else if (!strcmp(Choice, "10")) {
            DeleteLast(L);
        }
        else if (!strcmp(Choice, "11")) {
            printf("请输入要删除的元素：");
            scanf("%d", &X);
            DeleteElement(X, L);
        } 
        else if (!strcmp(Choice, "12")) {
            printf("请输入要删除的位置：");
            scanf("%d", &pos);
            DeleteIndex(pos, L);
        }
        else if (!strcmp(Choice, "13")) {
            printf("请输入要插入的元素：");
            scanf("%d", &X);
            Push_front(X, L);
            printf("插入成功！\n");
        }
        else if (!strcmp(Choice, "14")) {
            printf("请输入要插入的元素：");
            scanf("%d", &X);
            Push_back(X, L);
            printf("插入成功！\n");
        }
        else if (!strcmp(Choice, "15")) {
            printf("请输入要插入的元素：");
            scanf("%d", &X);
            printf("请输入要插入的位置：");
            scanf("%d", &pos);
            Insert(X, pos, L);
            printf("插入成功！\n");
        }
        else if (!strcmp(Choice, "16")) {
            printf("是否选择降序排序？(y/n)：");
            getchar();
            scanf("%c", &choice);
            if (choice == 'y') {
                SortList(L, false);
            } else if (choice == 'n') {
                SortList(L, true);
            } else {
                printf("输入有误，请重新输入！\n");
            }
        }
        else if (!strcmp(Choice, "17")) {
            printf("当前链表的长度为%d\n", Length(L));
        }
        else if (!strcmp(Choice, "18")) {
            printf("请确认是否删除当前链表？您存储的数据将会全部丢失！(y/n)：");
            getchar();
            scanf("%c", &choice);
            if (choice == 'y') {
                DeleteList(L);
            } else if (choice != 'n') {
                printf("输入有误，请重新输入！\n");
            }
        }
        else {
            printf("暂时没有该选项哦，请重新选择~\n");
        }
        system("pause");
        system("cls");
    }

    return 0;
}

void MakeEmpty(List L)
{
    L->Next = NULL;
    L->Element = 0;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(ElementType X, List L)
{
    int pos = FindIndex(X, L);
    if (pos == -1) {
        return pos;
    } else {
        return pos == L->Element;
    }
}

void ShowList(List L)
{
    if (IsEmpty(L)) {
        printf("当前链表为空！\n");
    } else {
        Position P = L->Next;
        while(P != NULL) {
            if (P->Next == NULL) {
                printf("%d\n", P->Element);
            } else {
                printf("%d-", P->Element);
            }
            P = P->Next;
        }
    }
}

ElementType FindFirst(List L)
{
    if (L->Next == NULL) {
        printf("当前链表为空！\n");
        return -1;
    } else {
        return L->Next->Element;
    }
}

ElementType FindLast(List L)
{
    if (L->Next == NULL) {
        printf("当前链表为空！\n");
        return -1;
    } else {
        Position P = FindElement(L->Element, L);
        return P->Element;
    }
}

int FindIndex(ElementType X, List L)
{
    int pos = 1;
    Position P = L->Next;
    while (P != NULL && P->Element != X) {
        P = P->Next;
        pos++;
    }
    if (P == NULL) {
        printf("当前链表不存在该元素！！\n");
        return -1;
    } else {
        return pos;
    }
}

Position FindElement(int pos, List L)
{
    Position P = L;
    if (pos > L->Element) {
        printf("指定位置超出链表长度！！\n");
        return NULL;
    } else {
        while (pos != 0) {
            P = P->Next;
            pos--;
        }
        return P;
    }
}

int FindPreIndex(ElementType X, List L)
{
    int pos = 0;
    Position P = L;
    while ( P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
        pos++;
    }
    if (P->Next == NULL) {
        printf("当前链表不存在该元素！！\n");
        return -1;
    } else {
        return pos;
    }
}

void DeleteFirst(List L)
{
    if (L->Next == NULL) {
        printf("当前链表为空！\n");
    } else {
        Position TmpCell = L->Next;
        L->Next = TmpCell->Next;
        free(TmpCell);
    }
    L->Element--;
    printf("删除成功!\n");
}

void DeleteLast(List L)
{
    if (L->Next == NULL) {
        printf("当前链表为空！\n");
    } else {
        Position P = FindElement(L->Element-1, L);
        Position TmpCell = P->Next;
        P->Next = NULL;
        free(TmpCell);
    }
    L->Element--;
    printf("删除成功!\n");
}

void DeleteElement(ElementType X, List L)
{
    if (L->Next == NULL) {
        printf("当前链表为空！\n");
        return;
    }
    Position TmpCell, P;
    int pos = FindPreIndex(X, L);
    if (pos == -1) return;
    P = FindElement(pos, L);
    TmpCell = P->Next;
    P->Next = TmpCell->Next;
    free(TmpCell);
    L->Element--;
    printf("删除成功!\n");
}

void DeleteIndex(int pos, List L)
{
    if (L->Next == NULL) {
        printf("当前链表为空！\n");
        return;
    }
    if (pos > L->Element) {
        printf("指定位置超出链表长度！！\n");
        return;
    }
    Position P = FindElement(pos-1, L);
    Position TmpCell = P->Next;
    P->Next = TmpCell->Next;
    free(TmpCell);
    L->Element--;
    printf("删除成功!\n");
}

void Push_front(ElementType X, List L)
{
    Insert(X, 1, L);
}

void Push_back(ElementType X, List L)
{
    Insert(X, L->Element+1, L);
}

void Insert(ElementType X, int pos, List L)
{
    Position TmpCell, P;
    if (pos > L->Element+1) {
        printf("指定位置超出链表范围！！\n");
    }
    else {
        P = FindElement(pos-1, L);
        TmpCell = (Position)malloc(sizeof(struct Node));
        TmpCell->Element = X;
        TmpCell->Next = P->Next;
        P->Next = TmpCell;
    }
    L->Element++;
}

void SortList(List L, bool ASC)
{
    int cnt, tmp;
    if (IsEmpty(L)) {
        printf("当前链表为空！\n");
    } else {
        if (ASC == true) {
            while (true) {
                cnt = 0;
                Position P = L->Next;
                while (P->Next != NULL) {
                    if (P->Element > P->Next->Element) {
                    tmp = P->Element;
                    P->Element = P->Next->Element;
                    P->Next->Element = tmp; 
                    cnt++;
                    }
                    P = P->Next;
                }
                if (cnt == 0) break;
            }
        } else {
            while (true) {
                cnt = 0;
                Position P = L->Next;
                while (P->Next != NULL) {
                    if (P->Element < P->Next->Element) {
                    tmp = P->Element;
                    P->Element = P->Next->Element;
                    P->Next->Element = tmp; 
                    cnt++;
                    }
                    P = P->Next;
                }
                if (cnt == 0) break;
            }
        }
    }
    printf("排序成功！\n");
}

ElementType Length(List L)
{
    return L->Element;
}

void DeleteList(List L)
{
    Position P, Tmp;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
    L->Element = 0;
    printf("删除成功！\n");
}