//
// Created by zsh96 on 2018/3/19.
//

/*
 * RMQ DP 二分
 * */

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXSIZE = 1e6;
const int LogMAX = log2(MAXSIZE);

int F[1000001][32];
int N;

int log2(int x){
    int n = 0;
    while((1<<n)<=x){
        n++;
    }
    return n-1;
}

void init(){
    int length = log2(N);
    for(int j=1; j<=length; j++){
        for(int i=1; i<=N-(1<<j)+1; i++){
            F[i][j] = min(F[i][j-1], F[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int i, int j){
    int k = log2(j-i+1);
    return min(F[i][k], F[j-(1<<k)+1][k]);
}

int main(){
    memset(F, 0x00, sizeof(F));
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &F[i][0]);
    }
    init();
    int M;
    scanf("%d", &M);
    int a,b;
    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", query(a, b));
    }
    cin.ignore();
    cin.get();
}