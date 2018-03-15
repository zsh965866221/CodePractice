//
// Created by zsh_o on 2018/3/15.
//

#include <iostream>
#include <cstring>
#include <limits.h>

using namespace std;

const int MAXN = 1e6;
const int MAXSIZE = 2*MAXN;
int Tree[2*MAXSIZE];
int Lazys[2*MAXSIZE];
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
        Tree[i] = Tree[i<<1] + Tree[i<<1|1];
    }
}

void change(int id, int value){
    int tid = N+id-1; //该节点Tree数组中的位置
    Tree[tid] = value;
    while(tid>1){
        tid = tid>>1;
        Tree[tid] = Tree[tid<<1] + Tree[tid<<1|1];
    }
}
int seg_change(int i, int j, int p, int q, int value, int id){
    if(i<=p && j>=q){
        Lazys[id] = value;
        //这里只是简单的把区间内的数全部设定同一个值
        Tree[id] = value * (q-p+1);
        return Tree[id];
    }
    if(p>j || q<i){
        return Tree[id];
    }
    if(Lazys[id]!=-1){
        Lazys[id<<1] = Lazys[id];
        Tree[id<<1] = ((q-p+1)>>1) * Lazys[id];
        Lazys[id<<1|1] = Lazys[id];
        Tree[id<<1|1] = ((q-p+1)>>1) * Lazys[id];
        Lazys[id] = -1;
    }
    int a = seg_change(i, j, p, (p+q)>>1, value, id<<1);
    int b = seg_change(i, j, ((p+q)>>1)+1, q, value, id<<1|1);
    //后序遍历刷新和
    Tree[id] = a+b;
    return Tree[id];
}

//[i,j]要查询的区间，[p,q]当前节点表示的区间，id当前节点下标
int query(int i, int j, int p, int q, int id){
    if(i<=p && j>=q){
        return Tree[id];
    }
    //求和，不在查询区间内的返回0
    if(p>j || q<i){
        return 0;
    }
    if(Lazys[id]!=-1){
        Lazys[id<<1] = Lazys[id];
        Tree[id<<1] = ((q-p+1)>>1) * Lazys[id];
        Lazys[id<<1|1] = Lazys[id];
        Tree[id<<1|1] = ((q-p+1)>>1) * Lazys[id];
        Lazys[id] = -1;
    }
    //左移可以使用id<<1|1，右移相当于/2不可以这样用，只能((p+q)>>1)+1
    int a1 = query(i, j, p, (p+q)>>1, id<<1);
    int a2 = query(i, j, ((p+q)>>1)+1, q, id<<1|1);
    return a1 + a2;
}

int main(){
    memset(Tree, 0x00, sizeof(Tree));
    memset(A, 0x00, sizeof(A));
    memset(Lazys, 0xff, sizeof(Lazys)); //全部设置为-1
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
            int d;
            scanf("%d", &d);
            seg_change(b, c, 1, N, d, 1);
        }
    }
    cin.ignore();
    cin.get();
}
