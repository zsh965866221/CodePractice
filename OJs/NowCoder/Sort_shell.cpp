#include <stdio.h>

void _swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}


int* shellSort(int* A, int n){
    int step = n / 2;
    while(step >= 1){
        for(int i=step; i<n; i++){
            for(int j=i; j-step>=0; j-=step){
                if(A[j] < A[j-step]){
                    _swap(A[j], A[j-step]);
                }
            }
        }
        step /= 2;
    }
    return A;
}

int main(){
int A[] = {7,4,5,8,2,6,1,4};
    int l = sizeof(A) / sizeof(int);
    shellSort(A, l);
    for(int i=0; i<l; i++){
        printf("%d ", A[i]);
    }
}
