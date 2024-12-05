//Tree Traversals Again
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 20
typedef struct {
	int Data[MaxSize];
	int Top;
} Stack;

int pre[MaxSize], in[MaxSize], post[MaxSize];

void PostOrder(int prel, int inl, int postl, int n)
{
	if (n == 0)
		return;
	if (n == 1)
	{
		post[postl] = pre[prel];
		return;
	}
	int root = pre[prel];
	post[postl + n - 1] = root;
    int i;
	for (i = 0; i < n; i++)
	{
		if (in[inl + i] == root)
			break;
	}
	int L = i;
	int R = n - (L + 1);
	PostOrder(prel + 1, inl, postl, L);
	PostOrder(prel + L + 1, inl + L + 1, postl + L, R);
}

void Push ( Stack *PtrS, int item )
{
	if ( PtrS->Top == MaxSize-1 ) {
        printf("堆栈满");
        return;
    } else {
        PtrS->Top++;
        PtrS->Data[PtrS->Top] = item;
    }
}

int Pop( Stack *PtrS )
{
    if (PtrS->Top==-1) {
        printf("堆栈空");
    } else {
        return(PtrS->Data[(PtrS->Top)--]);
    }
}

int main()
{
    Stack S;
    S.Top = -1;
    int n, r, i;
    char str[5];
    scanf("%d", &n);
    int u = 0;
    int v = 0;
    do {
        
        scanf("%s", str);
        if ( strcmp(str, "Push") == 0 ) {
            u++;
            scanf("%d", &r);
            pre[u-1] = r;
            Push(&S, r); 
        }
        else if ( strcmp(str, "Pop") == 0 ) {
            v++;
            in[v-1] = Pop(&S);
        }
        else printf("未知命令，请重试");
    } while ((u+v)!=2*n);
    printf("先序遍历为：");
    for (i=0; i<n; i++) {
        printf("%d ", pre[i]);
    }
    printf("\n");
    printf("中序遍历为：");
    for (i=0; i<n; i++) {
        printf("%d ", in[i]);
    }
    printf("\n");
    PostOrder(0, 0, 0, n);
    printf("后序遍历为：");
    for (i=0; i<n; i++) {
        printf("%d ", post[i]);
    }
    return 0;
}