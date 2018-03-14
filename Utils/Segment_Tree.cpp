//
// Created by zsh_o on 2018/3/9.
//

/*
 * 线段树，节点的更改和查询都是O(logN)
 * 需要把节点数量扩展成满2次幂的数，这样可以直接使用下标定位树中的节点，设扩展后的节点数为N那么该数一共有2N-1个节点，N-1个非叶子节点表示区间和N个叶子节点表示原始数据
 * */
#include <iostream>
using namespace std;

#define MAXN 1e6;
#define MAXSIZE 2*MAXN;
int Tree[];
int A[MAXSIZE];
int N;

