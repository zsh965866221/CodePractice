#include <stdio.h>
#include <string.h>

const int MAXN = 1000;
const int MAXD = 1000;

char S[MAXN];
int DP[MAXN][MAXD];

int n, d;

int main(){
    memset(DP, 0x00, sizeof(DP));
    scanf("%s%d", S, &d);
    n = strlen(S);
    DP[0][S[0] % d] = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<d; j++){
            DP[i][j] += DP[i-1][j];
            DP[i][(j * 10 + S[i] - '0') % d] += DP[i-1][j];
            if(S[i] % d == j){
                DP[i][j]++;
            }
        }
    }
    printf("%d\n", DP[n-1][0]);
    for(int i=0; i<n; i++){
        for(int j=0; j<d; j++){
            printf("%d ", DP[i][j]);
        }
        printf("\n");
    }
}
