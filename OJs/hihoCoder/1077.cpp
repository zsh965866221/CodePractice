//
// Created by zsh_o on 2018/3/14.
//

/*
 * 线段树，节点的更改和查询都是O(logN)
 * 需要把节点数量扩展成满2次幂的数，这样可以直接使用下标定位树中的节点，设扩展后的节点数为N那么该数一共有2N-1个节点，N-1个非叶子节点表示区间和N个叶子节点表示原始数据
 * */
#include <iostream>
#include <cstring>
#include <limits.h>

using namespace std;

const int MAXN = 1e6;
const int MAXSIZE = 2*MAXN;
int Tree[2*MAXSIZE];
int A[MAXSIZE];
int N;

void init(){
    //把N扩充为2的幂
    int t = 1;
    while(t<N)
        t = t<<1;
    N = t;

    //叶子节点位置：[N, 2N-1]
    for(int i=0; i<N; i++){
        Tree[N+i] = A[i];
    }

    //第i个节点左右子树的位置为[2*i, 2*i+1]=> [i<<1, i<<1|1]
    //Tree从1开始
    for(int i=N-1; i>=1; i--){
        Tree[i] = min(Tree[i<<1], Tree[i<<1|1]);
    }
}

void change(int id, int value){
    int tid = N+id-1; //该节点Tree数组中的位置
    Tree[tid] = value;
    while(tid>1){
        tid = tid>>1;
        Tree[tid] = min(Tree[tid<<1], Tree[tid<<1|1]);
    }
}

//[i,j]要查询的区间，[p,q]当前节点表示的区间，id当前节点下标
int query(int i, int j, int p, int q, int id){
    if(i<=p && j>=q){
        return Tree[id];
    }
    if(p>j || q<i){
        return INT_MAX;
    }
    //左移可以使用id<<1|1，右移相当于/2不可以这样用，只能((p+q)>>1)+1
    int a1 = query(i, j, p, (p+q)>>1, id<<1);
    int a2 = query(i, j, ((p+q)>>1)+1, q, id<<1|1);
    return min(a1, a2);
}

int main(){
    memset(Tree, 0x7F, sizeof(Tree));
    memset(A, 0x7F, sizeof(A));
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    init();
    int Q;
    scanf("%d", &Q);
    for(int i=0; i<Q; i++){
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        if(a==0){
            cout<<query(b, c, 1, N, 1)<<endl;
        }else{
            change(b, c);
        }
    }
    cin.ignore();
    cin.get();
}
