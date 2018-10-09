#include <stdio.h>
#include <string.h>

const int MAXA = 1e9 ;
const int MINA = -1e9;
int* countingSort(int* A, int n) {
    // write code here
    int maxa = MINA; int mina = MAXA;
    for(int i=0; i<n; i++){
        maxa = A[i] > maxa ? A[i] : maxa;
        mina = A[i] < mina ? A[i] : mina;
    }
    int l = maxa - mina + 1;
    int* C = new int[l];
    memset(C, 0x00, sizeof(int)*l);
    for(int i=0; i<n; i++){
        C[A[i] - mina]++;
    }
    for(int i=0; i<l; i++){
        printf("%d ", C[i]);
    }
    int index = 0;
    for(int i=0; i<l; i++){
        for(int j=0; j<C[i]; j++){
            A[index] = i + mina;
            index++;
        }
    }
    delete C;
    return A;
}


int main(){
    int A[] = {7,4,5,8,2,6,1,4};
    int l = sizeof(A) / sizeof(int);
    countingSort(A, l);
    for(int i=0; i<l; i++){
        printf("%d ", A[i]);
    }
}
