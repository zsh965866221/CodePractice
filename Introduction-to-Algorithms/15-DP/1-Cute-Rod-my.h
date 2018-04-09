//
// Created by zsh_o on 2018/4/5.
//

/**
 * 用表保存子问题的解，F[i]长度为i时最大值1->N
 * */

#include "../common.h"

int Cute_Rod_My(int P[], int N){
    int F[N+1];
    F[0] = 0;
    for(int i=1; i<=N; i++){
        int t = -1;
        for(int j=1; j<=i; j++){
            t = max(t, P[j] + F[i-j]);
        }
        F[i] = t;
    }
    return F[N];
}