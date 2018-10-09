#include <stdio.h>
#include <memory.h>
#include <string.h>

const int MAXN = 1000;
const int MAXA = 1e9;

//char S[MAXN];
int F[MAXN];
int n;
int main(){
    //scanf("%s", S);
    char* S = "aabccabcb";
    n = strlen(S);
    F[0] = 1;
    int i = 1;
    int j = 0;
    while(i<n){
        j = 0;
        while((j < F[i-1]) && (S[i] != S[i-1-j])){
            j++;
        }
        F[i] = j + 1;
        i++;
    }
    for(int i=0; i<n; i++){
        printf("%c ", S[i]);
    }
    printf("\n");
    int maxl = -MAXA;
    for(int i=0; i<n; i++){
        maxl = F[i] > maxl ? F[i] : maxl;
        printf("%d ", F[i]);
    }
    printf("\n");
    printf("%d\n", maxl);

}
