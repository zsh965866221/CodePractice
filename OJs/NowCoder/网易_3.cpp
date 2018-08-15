// 二分查找

#include <stdio.h>
#include <string.h>

const int MAXN = 1e5 + 1;
const int MAXM = 1e5 + 1;

int n, m, a, q;
int A[MAXN];
int SUMA[MAXN];

int _find_i(int* sumA, int n, int q){
    int left = 0;
    int right = n;
    int mid;
    while(left < right - 1){
        mid = (left + right  + 1) / 2;
        int c = sumA[mid];
        if(q <= c){
            right = mid;
        }else{
            left = mid;
        }
    }
    mid = (left + right + 1) / 2;
    return mid;
}

int main(){
    memset(A, 0x00, sizeof(A));
    memset(SUMA, 0x00, sizeof(SUMA));
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a);
        A[i] = a;
        SUMA[i] = SUMA[i-1] + a;
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &q);
        printf("%d\n", _find_i(SUMA, n, q));
    }
}
