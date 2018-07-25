/**
 * 冒泡排序
*/

#include <stdio.h>
#include <string.h>

void _swap(int& a, int& b){
//    a = a + b;
//    b = a - b;
//    a = a - b;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int* bubbleSort(int* A, int n){
    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i; j--){
            if(A[j-1] > A[j]){
//                int t = A[j-1];
//                A[j-1] = A[j];
//                A[j] = t;
                _swap(A[j-1], A[j]);
            }
        }
    }
    return A;
}

int main(){
    int A[] = {4,1,3,5,3,2,1};
    int l = sizeof(A) / sizeof(int);
    bubbleSort(A, l);
    for(int i=0; i<l ;i++){
        printf("%d ", A[i]);
    }
}
