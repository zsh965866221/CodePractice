#include <stdio.h>
#include <string.h>

const int MAXN = 100 + 1;
const int MAXV = 999 + 1;

int A[MAXN];
int B[MAXN];
int dp[MAXN + 1];
int N;

int _max(int a, int b){
    return a>b? a:b;
}
int _min(int a, int b){
    return a<b? a:b;
}
void _swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
int a, b;
int main(){
    memset(A, 0x00, sizeof(A));
    memset(B, 0x00, sizeof(B));
    memset(dp, 0x00, sizeof(dp));
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d%d", &a, &b);
        A[i] = _min(a, b);
        B[i] = _max(a, b);
    }
    A[0] = -MAXV;
    B[0] = -MAXV;

    //先按a排序
    for(int i=N; i>0; i--){
    	for(int j=0; j<i; j++){
            if(A[j] > A[j+1]){
            	_swap(A[j+1], A[j]);
                _swap(B[j+1], B[j]);
            }
        }
    }
    for(int i=0; i<=N; i++){
        printf("%d-%d ", A[i], B[i]);
    }
    printf("\n");
    //再按b排序
    for(int i=N; i>0; i--){
    	for(int j=0; j<i; j++){
            if(B[j] > B[j+1]){
            	_swap(A[j+1], A[j]);
                _swap(B[j+1], B[j]);
            }
        }
    }

    for(int i=0; i<=N; i++){
        printf("%d-%d ", A[i], B[i]);
    }
    printf("\n");

    //动规求解
    dp[0] = 0;
    dp[1] = 1;
    for(int i=1; i<=N; i++){
    	//寻找j<=A[i]
        int j = i;
        while(j>=0 && B[j]>A[i]){
            j--;
        }
        dp[i] = _max(dp[i-1], dp[j] + 1);
    }
    printf("%d\n", dp[N]);
}

