#include <stdio.h>

const int MAXN = 100 + 1;
const int MAXM = 100 + 1;
const int MAXK = 1e9 + 1;

int n, m, k;

int main(){
    scanf("%d%d%d", &n, &m, &k);
    // 计算(m+n, n)组合数
    long long C = 1;
    for(int i=0; i<n; i++){
        C *= (m + n - i);
    }
    for(int i=1; i<=n; i++){
        C /= i;
    }

    if(k > C){
        printf("-1\n");
        return 0;
    }

    int i = n; int j = m;
    while(!(i==0 & j==0)){
        if(i == 0){
            printf("z");
            j--;
            continue;
        }
        if(j == 0){
            printf("a");
            i--;
            continue;
        }

        int Cp = C * i / (i + j);
        int Cq = C * j / (i + j);
        if(k > Cp){
            printf("z");
            k -= Cp;
            j--;
            C = Cq;
        }else{
            printf("a");
            i--;
            C = Cp;
        }
    }
    printf("\n");
}
