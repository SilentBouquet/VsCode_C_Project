//Huffman Codes
//注意：最优编码不一定通过Huffman算法得到
/*
Huffman Codes的特点：
1. 最优编码————（WPL）最小
2. 无歧义编码————前缀码：数据仅存于叶子结点
3. 没有度为1的结点————满足1、2则必有3
注意：满足2、3可不一定有1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 64
typedef struct TreeNode *HuffmanTree;
struct TreeNode {
    int Weight;
    HuffmanTree Left, Right;
};
typedef struct HeapStruct *MinHeap;
struct HeapStruct {
    HuffmanTree Elements[MaxSize];
    int Size;
};
char ch[MaxSize];
int N, w[MaxSize], TotalCodes;


MinHeap CreateMinHeap( int n )
{
    MinHeap H = (MinHeap)malloc(sizeof(struct HeapStruct));
    H->Size = 0;
    H->Elements[0] = (HuffmanTree)malloc(sizeof(struct TreeNode));
    H->Elements[0]->Weight = -1;
    H->Elements[0]->Left = H->Elements[0]->Right = NULL;

    return H;
}

HuffmanTree CreateHuffman()
{
	HuffmanTree  T;
	T = (HuffmanTree)malloc(sizeof(struct TreeNode));
	T->Left = T->Right = NULL;
	T->Weight = 0;

	return T;
}

void InsertMinHeap( MinHeap H, HuffmanTree HTree )
{
    int i = ++H->Size;
    for ( ; HTree->Weight < H->Elements[i/2]->Weight; i=i/2 ) {
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = HTree;
}

HuffmanTree DeleteMin(MinHeap H)
{
	HuffmanTree HTree;
	HTree=H->Elements[1]; 
	
	H->Elements[1]=H->Elements[H->Size--];
	int father,child; HuffmanTree tmp;
	father=1; 
	child=2*father; 

	while(child <= H->Size)
	{
		if( child+1 <= H->Size && H->Elements[child+1]->Weight < H->Elements[child]->Weight )
			child++;
		
		if(H->Elements[child]->Weight < H->Elements[father]->Weight)
		{
			tmp=H->Elements[father];
			H->Elements[father]=H->Elements[child];
			H->Elements[child]=tmp;
			father=child;
			child=2*father;
		}
		else
			break;	
	}
	return HTree;
}


HuffmanTree Huffman( MinHeap H )
{
    int i; HuffmanTree T;
    for ( i=1; i<H->Size; i++ ) {
        T = CreateHuffman();
        T->Left = DeleteMin(H);
        T->Right = DeleteMin(H);
        T->Weight = T->Left->Weight + T->Right->Weight;
        InsertMinHeap(H,T);
    }
    T = DeleteMin(H);
    return T;
}

int WPL( HuffmanTree T, int Depth )
{
    if ( !T->Left && !T->Right )
        return (Depth*T->Weight);
    else
        return (WPL(T->Left, Depth+1) + WPL(T->Right, Depth+1));
}

int Judge()
{
	HuffmanTree T, p;
	char chl, *codes;
	codes = (char *)malloc(sizeof(char)*MaxSize);
	int length = 0, flag = 1, wgh, j;
	T = CreateHuffman();
	
	for ( int i = 0; i < N; i++ )
	{
		scanf("\n%c %s", &chl, codes);
		if ( strlen(codes) >= N )
			flag = 0;
		else {
			for ( j = 0; chl !=ch[j]; j++ );
			wgh = w[j];
			p = T;
			for ( j = 0; j < strlen(codes); j++ )
			{
				if ( codes[j]=='0' ) {
					if ( !p->Left )
						p->Left = CreateHuffman();
					p = p->Left;
					
				} else if( codes[j] == '1' ) {
					if( !p->Right )
						p->Right = CreateHuffman();
					p = p->Right;
				}
				if (p->Weight) flag = 0;
			}
			if ( p->Left || p->Right )
				flag = 0;
			else
				p->Weight = wgh;
		}
		length += strlen(codes)*p->Weight;
	}
	if ( length!=TotalCodes )
		flag = 0;
	return flag;
}

int main()
{
    int M;
    HuffmanTree tmp, root;
    scanf("%d", &N);
    MinHeap H = CreateMinHeap( N );
    for ( int i = 0; i < N; i++ ) {
        getchar();
        scanf("%c %d", &ch[i], &w[i]);
        tmp = CreateHuffman();
        tmp->Weight = w[i];
        InsertMinHeap(H, tmp);
    }
    root = Huffman(H);
    TotalCodes = WPL(root, 0);
    scanf("%d", &M);
    for ( int i = 0; i < M; i++ ) {
        if (Judge())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}