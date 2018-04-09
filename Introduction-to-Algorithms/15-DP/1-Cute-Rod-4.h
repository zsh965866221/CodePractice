//
// Created by zsh_o on 2018/4/5.
//
/**
 * 用数组S保存每次的要截断的长度
 * */

#include "../common.h"

int Extended_Bottom_Up_Cut_Rod(int P[], int N){
    int S[N+1];
    int R[N+1];
    S[0] = R[0] = 0;
    for(int i=1; i<=N; i++){
        R[i] = 0;
        for(int j=1; j<=i; j++){
            if(P[j]+R[i-j] > R[i]){
                R[i] = P[j] + R[i-j];
                S[i] = j;
            }
        }
    }
    int index = N;
    while(index>0){
        cout<<S[index]<<" ";
        index -= S[index];
    }
    cout<<endl;

    return R[N];
}
