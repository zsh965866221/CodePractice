#include <stdio.h>
#include <string.h>

const int MAXN = 1000 + 1;
const int MAXA = 1e5;
const int MAXK = 10000;
int n, k;
int A[MAXA];
int N[MAXN];
int X[MAXK];
int Y[MAXK];
int a;
int main(){
    memset(N, 0x00, sizeof(N));
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%d", &a);
        A[i] = a;
        N[a]++;
    }
    int index;
    for(index=0; index<k; index++){
        //find max and min
        int mini = -1; int maxi = -1;
        int mina = MAXA+1; int maxa = -1;
        for(int i=1; i<=n; i++){
            if(A[i] < mina){
                mina = A[i];
                mini = i;
            }
            if(A[i] > maxa){
                maxa = A[i];
                maxi = i;
            }
        }
        int res = k-index;
        if(N[mina] > res & N[maxa] > res){
            break;
        }
        A[mini]++;
        A[maxi]--;
        N[mina]--;
        N[mina+1]++;
        N[maxa]--;
        N[maxa-1]--;
        X[index] = maxi;
        Y[index] = mini;
    }
    int mini = -1; int maxi = -1;
    int mina = MAXA+1; int maxa = -1;
    for(int i=1; i<=n; i++){
        if(A[i] < mina){
            mina = A[i];
            mini = i;
        }
        if(A[i] > maxa){
            maxa = A[i];
            maxi = i;
        }
    }
    printf("%d %d\n", maxa-mina, index);
    for(int i=0; i<index; i++){
        printf("%d %d\n", X[i], Y[i]);
    }
}
