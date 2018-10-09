#include <stdio.h>
#include <string.h>

const int MAXN = 50 + 1;
const int MAXA = 60000 + 1;

/**
 * F[i][j]@k，A队的水平之和为i最小水平为j时的方案数，k为选择队员k时的状态判断
 * 满足条件需要判断, (2*i - Sum < 2 * j) && (2 * i > Sum)
 *
*/


// F[i][j]: i，
// dp方法求解，每一个和都对应着
int F[MAXA * MAXN][MAXN];
int A[MAXN];
int n;
int a;
int res;
int Sum;
int main(){
    scanf("%d", &n);
    res = 0;
    Sum = 0;
    for(int i=1; i<=n; i++){
        scanf("%d", &a);
        A[i] = a;
        Sum += a;
    }
    A[0] = 0;
    memset(F, 0x00, sizeof(F));
    F[0][0] = 1;
    for(int k=1; k<=n ;k++){ // 第k个队员
        for(int i=Sum; i>0; i--){
            for(int j=1; j<=n; j++){
                if(F[i][j] > 0){
                    // 选择k
                    if(A[k] <= A[j]){ // 刷新最小值 i==0
                        F[i + A[k]][k] ++;
                    }else{
                        F[i + A[k]][j] ++;
                    }
                    // 不选择k
                    F[i][j] = F[i][j];
                }
            }
        }
        F[A[k]][k] ++;
    }
    for(int i=1; i<=Sum; i++){
        for(int j=1; j<=n; j++){
            if((2 * i - Sum < 2 * A[j]) && (2 * i > Sum)){
                res += F[i][j];

            }
        }
    }
    printf("%d\n", res);
    printf("---");
    for(int j=0; j<=n; j++){
        printf("\t%d", A[j]);
    }
    printf("\n");
    printf("-------------------------------------------------\n");
    for(int i=0; i<=Sum; i++){
        printf("%d - ", i);
        for(int j=0; j<=n; j++){
            printf("\t%d", F[i][j]);
        }
        printf("\n");
    }
}
