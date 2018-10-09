// 0 1 背包
#include <stdio.h>
#include <string.h>

const int MAXW = 1000 + 1;
const int MAXC = 1000;
int DP[MAXC][MAXW];
int path[MAXC][MAXW];
int WL[MAXC];
int V[MAXC];
int W, C;

int max(int a, int b){
    return a>b? a : b;
}

int main(){
    scanf("%d%d", &W, &C);
    for(int i=0; i<C; i++){
        scanf("%d %d", &WL[i], &V[i]);
    }
    memset(DP, 0x00, sizeof(DP));
    memset(path, 0x00, sizeof(path));
    for(int j=1; j<=W; j++){
        if(j >= WL[0]){
            DP[0][j] = V[0];
            path[0][j] = 1;
        }
    }
    for(int i=1; i<C; i++){
        for(int j=1; j<=W; j++){
            DP[i][j] = DP[i-1][j];
            int pre_w = j - WL[i];
            if(pre_w >= 0 && DP[i-1][pre_w] + V[i] > DP[i][j]){
                DP[i][j] = DP[i-1][pre_w] + V[i];
                path[i][j] = 1;
            }
        }
    }
    printf("%d\n", DP[C-1][W]);
    for(int i=0; i<C; i++){
        for(int j=0; j<=W; j++){
            printf("[%d,%d] ", DP[i][j], path[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<C; i++){
        printf("%d ", path[i][W]);
    }
    printf("\n");
}
