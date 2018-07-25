/**
 * 插入排序
*/

#include <stdio.h>
#include <string.h>

void _swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

int* insertSort(int* A, int n){
    for(int i=1; i<n; i++){
        for(int j=i; j>=0; j--){
            if(A[j] < A[j-1]){
                _swap(A[j], A[j-1]);
            }
        }
    }
    return A;
}

int main(){
    int A[] = {7,4,5,8,2,6,1,4};
    int l = sizeof(A) / sizeof(int);
    insertSort(A, l);
    printf("\n");
    for(int i=0; i<l; i++){
        printf("%d ", A[i]);
    }
}
