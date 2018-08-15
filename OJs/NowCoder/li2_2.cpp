#include <stdio.h>
#include <string.h>

const int MAXN = 100 + 1;
const int MAXM = 100 + 1;
const int MAXK = 1e9 + 1;

int n, m, k;

long D[MAXN][MAXM];
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<=n; i++){
        D[i][0] = 1;
    }
    for(int j=0; j<=m; j++){
        D[0][j] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            long t = D[i-1][j] + D[i][j-1];
            D[i][j] = t > MAXK + 1 ? MAXK + 1 : t;
        }
    }
    if(k > D[n][m]){
        printf("-1\n");
        return 0;
    }
    int i = n;
    int j = m;
    while(!(i==0 & j==0)){
        if(i==0){
            printf("z");
            j--;
            continue;
        }
        if(j==0){
            printf("a");
            i--;
            continue;
        }

        int Cp = D[i-1][j];
        if(k > Cp){
            printf("z");
            k -= Cp;
            j--;
        }else{
            printf("a");
            i--;
        }
    }
    printf("\n");
}
