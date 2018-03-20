//
// Created by zsh_o on 2018/3/20.
//

/*
 * 解体思路参考：http://hihocoder.com/contest/offers51/solution/1286796
 * */

#include <iostream>
#include <limits.h>

using namespace std;

const int MAXSIZE = 100000+1;
int A[MAXSIZE];
int SUB[MAXSIZE];
int NUMM[MAXSIZE];
int F[MAXSIZE][32]; //记录最大长度位置
int M, N;

int log2(int x){
    int t = 0;
    while((1<<t)<=x){
        t++;
    }
    return t-1;
}

void init(){
    for(int i=1; i<=N; i++){
        F[i][0] = i;
    }
    int t = log2(N);
    for(int j=1; j<=t; j++){
        for(int i=1; i<=N-(1<<j)+1; i++){
            int a1 = F[i][j-1];
            int a2 = F[i+(1<<(j-1))][j-1];
            F[i][j] = NUMM[a1] >= NUMM[a2]? a1 : a2;
        }
    }
}
int query(int a, int b){
    int t = log2(b-a+1);
    int a1 = F[a][t];
    int a2 = F[b-(1<<t)+1][t];
    return NUMM[a1] >= NUMM[a2]? a1 : a2;
}
int main(){
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++){
        scanf("%d", &A[i]);
    }
    SUB[1] = INT_MAX;
    NUMM[1] = 1;
    for(int i=2; i<=N; i++){
        SUB[i] = A[i] - A[i-1];
        NUMM[i] = SUB[i]==SUB[i-1]? NUMM[i-1]+1 : 2;
    }

    init();

    int a, b;
    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        int idx = query(a, b);
        if(a <= idx - NUMM[idx] +1)
            printf("%d\n", NUMM[idx]);
        else{
            int t = idx - a + 1;
            if(idx == b)
                printf("%d\n", t);
            else
                printf("%d\n", max(t, NUMM[query(idx+1, b)]));
        }
    }
    cin.ignore();
    cin.get();
}