#include <stdio.h>
#include <string.h>

void _swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

int _partition(int* A, int left, int right){
    int k = A[right];
    int i = left, j = left;
    while(j <= right){
        if(A[j] <= k){
            _swap(A[i], A[j]);
            i++;
        }
        j++;
    }
    return i - 1;
}
void quickSort(int* A, int left, int right){
    if(left<right){
        int m = _partition(A, left, right);
        quickSort(A, left, m - 1);
        quickSort(A, m + 1, right);
    }
}
int* quickSort(int* A, int n){
    quickSort(A, 0, n - 1);
    return A;
}

int* quickSort_nonRecursive(int* A, int n){
    int Stack[10000];
    int head = -1;
    Stack[++head] = 0;
    Stack[++head] = n - 1;
    while(head > 0){
        int right = Stack[head--];
        int left = Stack[head--];
        if(left < right){
            int m = _partition(A, left, right);
            Stack[++head] = left;
            Stack[++head] = m - 1;

            Stack[++head] = m + 1;
            Stack[++head] = right;
        }
    }
    return A;
}

int main(){
    int A[] = {7,4,5,8,2,6,1,4};
    int l = sizeof(A) / sizeof(int);
    quickSort_nonRecursive(A, l);
    for(int i=0; i<l; i++){
        printf("%d ", A[i]);
    }
}
