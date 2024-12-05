#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20

int cmp(const void *a, const void *b) {
	return *(int *)b > *(int *)a;
}
int main() {
    int K; 
    scanf("%d",&K);
    int arr[MaxSize];
    for (int i = 0; i < K; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < K; i++) {
        int num = arr[i];
        while (num != 1) {
            if(num % 2 == 0) {
				num /= 2;
			} else {
				num = (3*num + 1) / 2;
			}
            for (int j = 0; j < K; j++) {
                if (arr[j] == num) {
                    arr[j] = 1;
                    break;
                }
            }
        }
    } 
	qsort(arr, K, sizeof(int), cmp);
	for (int i = 0; arr[i] != 1 && i < K; i++) {
		if(i != 0) {
			printf(" ");
		}
		printf("%d", arr[i]);
	}
}