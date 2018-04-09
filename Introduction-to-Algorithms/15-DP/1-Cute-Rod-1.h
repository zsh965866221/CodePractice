//
// Created by zsh_o on 2018/4/5.
//

/**
 * P206, 据钢条，自顶向下递归实现
 * 相当于直接搜索
 * 一共有n个长度，计算每次切割的长度
 * */

/*
10
1 5 8 9 10 17 17 20 24 30
10

30
 * */

#include "../common.h"

int Cute_Rod(int P[], int res){
    if(res == 0){
        return 0;
    }
    int t = -1;
    for(int i=1; i<=res; i++){
        t = max(t, P[i] + Cute_Rod(P, res - i));
    }
    return t;
}