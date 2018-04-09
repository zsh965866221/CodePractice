//
// Created by zsh_o on 2018/4/5.
//

#include "../common.h"

int Memoized_Cut_Rod_Aux(int P[], int R[], int res){
    if(R[res]>-1){
        return R[res];
    }
    int t = -1;
    for(int i=1; i<=res; i++){
        t = max(t, P[i] + Memoized_Cut_Rod_Aux(P, R, res-i));
    }
    R[res] = t;
}

int Memoized_Cut_Rod(int P[], int N){
    int R[N+1];
    memset(R, 0xff, sizeof(R));
    R[0] = 0;
    return Memoized_Cut_Rod_Aux(P, R, N);
}