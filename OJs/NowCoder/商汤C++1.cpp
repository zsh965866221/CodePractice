#include <stdio.h>
#include <string.h>

int str2dig(char c){
    int t = c - '0';
    return t;
}

const int MAXS = 1e5;
char S[MAXS];
int A[MAXS + 1];
int N;

int main(){
    S[0] = '0';
    scanf("%s", S + 1);
    N = strlen(S);
    A[0] = 1;
    A[1] = 1;
    for(int i=2; i<=N; i++){
        int j = i - 1;
        if(S[j] == '0' && S[j-1] == '0'){
            printf("0\n");
            return 0;
        }
        if(S[j] == '0'){
            A[i] = A[i - 2];
        }else if(S[j - 1] == '0'){
            A[i] = A[i - 1];
        }else{
            int t = str2dig(S[j-1]) * 10 + str2dig(S[j]);
            if(t <= 26){
                A[i] = A[i - 1] + A[i - 2];
            }else{
                A[i] = A[i - 1];
            }
        }

    }
    printf("%d", A[N]);
}
