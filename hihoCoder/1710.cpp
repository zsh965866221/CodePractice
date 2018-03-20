//
// Created by zsh_o on 2018/3/20.
//

/*
 * TLE
 * */

#include <iostream>
#include <limits.h>
using namespace std;

const int MAXSIZE = 100000+1;
int A[MAXSIZE];
int SUB[MAXSIZE];
int NUMM[MAXSIZE];
int M, N;

int query(int a, int b){
    int t = b;
    int result = 0;
    while(a<t){
        t = b - NUMM[b] + 1;
        if(NUMM[b]>result){
            if(t<a){
                result = max(b - a + 1, result); //防止当前的最大值发生在边界
            }else{
                result = NUMM[b];
            }
        }
        b = t;
    }
    return result;
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

    int a, b;
    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", query(a, b));
    }
    cin.ignore();
    cin.get();
}