//
// Created by zsh_o on 2018/4/5.
//

#include "../common.h"

int Bottom_Up_Cut_Rod(int P[], int N){
    int R[N+1];
    R[0] = 0;
    for(int i=1; i<=N; i++){
        int t = -1;
        for(int j=1; j<=i; j++){
            t = max(t, P[j] + R[i-j]);
        }
        R[i] = t;
    }
    return R[N];
}
