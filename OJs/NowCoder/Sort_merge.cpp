/**
 * 归并排序
*/

#include <stdio.h>
#include <string.h>

// T为辅助数组
int* _merge(int* A, int na, int* B, int nb, int* T){
    int i = 0, j = 0, k = 0;
    while(i < na & j < nb){
        if(A[i] < B[j]){
            T[k++] = A[i++];
        }else{
            T[k++] = B[j++];
        }
    }
    while(i < na){
        T[k++] = A[i++];
    }
    while(j < nb){
        T[k++] = B[j++];
    }
    return T;
}

int* _merge(int* A, int a, int m, int b, int* T){
    int i = a, j = m, k = 0;
    while(i < m & j < b){
        if(A[i] < A[j]){
            T[k++] = A[i++];
        }else{
            T[k++] = A[j++];
        }
    }
    while(i < m){
        T[k++] = A[i++];
    }
    while(j < b){
        T[k++] = A[j++];
    }
    for(int i=0; i<b-a; i++){
        A[a + i] = T[i];
    }
    return A;
}

void _binaryMerge(int* A, int a, int b, int* T){
    if(b - a <= 1){
        return;
    }
    int m = a + (b-a) / 2;
    _binaryMerge(A, a, m, T);
    _binaryMerge(A, m, b, T);

    //后序执行归并
    _merge(A, a, m, b, T);
}

int* mergeSrot(int* A, int n){
    int* T = new int[n];
    _binaryMerge(A, 0, n, T);
    return A;
}

int main(){
    int A[] = {7,4,5,8,2,6,1,4};
    int l = sizeof(A) / sizeof(int);
    mergeSrot(A, l);
    printf("\n");
    for(int i=0; i<l; i++){
        printf("%d ", A[i]);
    }
}

