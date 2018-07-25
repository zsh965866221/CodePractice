/**
 * 选择排序
 * 选择A[i, n-1]最小的k，交换A[i] A[k]，i in [0, n-2]
*/

#include <stdio.h>
#include <string.h>

void _swap(int& a, int& b){
//    a = a ^ b;
//    b = a ^ b;
//    a = a ^ b;
    a = a + b;
    b = a - b;
    a = a - b;
}

int* selectSort(int* A, int n){
    for(int i=0; i<n-1; i++){
        int k = i;
        for(int j=i; j<n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        if(i != k)
            _swap(A[i], A[k]); //会涉及到自身与自身的交换，这样不能采用不申请额外空间的交换方法
    }
    return A;
}

int main(){
    int A[] = {7,4,5,8,2,6,1,4};
    int l = sizeof(A) / sizeof(int);
    selectSort(A, l);
    printf("\n");
    for(int i=0; i<l; i++){
        printf("%d ", A[i]);
    }
}
