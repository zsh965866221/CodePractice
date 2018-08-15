/**
 * 6 3
 * 1 3 5 2 5 4
 * 1 1 0 1 0 0
**/


#include <stdio.h>
#include <string.h>

const int MAXN = 1e5 + 1;
const int MAXK = 1e5 + 1;
const int MAXA = 1e4 + 1;

int n, k;
int a, t;

int A[MAXN];
bool T[MAXN];

int main(){
    memset(A, 0x00, sizeof(A));
    memset(T, 0x00, sizeof(T));
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%d", &a);
        A[i] = a;
    }
    T[0] = true;
    for(int i=1; i<=n; i++){
        scanf("%d", &t);
        if(t == 0){
            T[i] = false;
        }else{
            T[i] = true;
        }
    }

    int c = 0; //µ±Ç°×´Ì¬
    int maxc = 0;
    int maxi = 0;
    int res = 0;
    int i;
    for(i=1; i<=n; i++){
        int pre_i = i - 1;
        if(T[pre_i] == false){ //Ë¯×Å
            c -= A[pre_i];
        }
        int next_i = i+k-1;
        if(next_i <= n && T[next_i] == false){
            c += A[next_i];
        }
        printf("%d - %d\n", i, c);

        if(c > maxc){
            maxc = c;
            maxi = i;
        }

        if(T[i] == true){
            res += A[i];
        }
    }
    for(int i=1; i<=k-1; i++){
        if(T[i] == false){
            res += A[i];
        }
    }
    printf("%d\n", res);
    printf("%d %d\n", maxi, res + maxc);
}
