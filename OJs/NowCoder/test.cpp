#include <stdio.h>
#include <string.h>

int main(){
    int A[100];
    A[0] = 4;
    int* p = A;
    printf("%d %d\n", A[0], p[0]);
    printf("%d %d\n", sizeof(A), sizeof(p));
}
