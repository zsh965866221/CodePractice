
#include <stdio.h>
#include <string.h>

const int MAXN = 1000 + 1;
const int MAXM = 1000 + 1;
int n, m, c;
int C[MAXN];
int main(){
    memset(C, 0x00, sizeof(C));
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d", &c);
        C[c]++;
    }
    int minc = MAXM + 1;
    for(int i=1; i<=n; i++){
        if(C[i]<minc){
            minc = C[i];
        }
    }
    printf("%d", minc);
}
