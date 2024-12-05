//栈的数组实现
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

void ShowMenu();
int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

int main()
{
    while (1) {
        ShowMenu();

        int ret, X, pos;
        char Choice[100] = "";
        char choice;
        printf("请选择要进行的操作：");
        scanf("%s", Choice);
        if (!strcmp(Choice, "q")) {

        }
    }
    return 0;
}

void ShowMenu()
{
    printf("");
}

int IsEmpty(Stack S)
{

}

int IsFull(Stack S)
{

}

Stack CreateStack(int MaxElements)
{

}

void DisposeStack(Stack S)
{

}

void MakeEmpty(Stack S)
{

}

void Push(ElementType X, Stack S)
{

}

ElementType Top(Stack S)
{

}

void Pop(Stack S)
{

}

ElementType TopAndPop(Stack S)
{

}