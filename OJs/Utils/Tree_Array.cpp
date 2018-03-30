//
// Created by zsh_o on 2018/3/9.
//

/*
 * 树状数组，又叫做 二叉索引树
 * n个数，q次询问，每次询问一个区间[x, y]的和
 * 最主要公式，计算第x项是前n项和中的n的值
 * n = x&(-x)
 * 需要配合前缀和数组和原始数组来使用
 * */

#include <iostream>

using namespace std;

const int MAXSIZE = 1000;
int ORGS[MAXSIZE];
int PRE[MAXSIZE];
int BST[MAXSIZE];
int CTSIZE;

int lowbit(int x){
    return x&(-x);
}

void init(){
    for(int i=1; i<=CTSIZE; i++){
        BST[i] = PRE[i] - PRE[i-lowbit(i)];
    }
}

int sum(int idx){
    int total = 0;
    while(idx>0){
        total += BST[idx];
        idx -= lowbit(idx);
    }
    return total;
}

//idx增加val
void update(int idx, int val){
    while(idx <= CTSIZE){
        BST[idx] += val;
        idx += lowbit(idx);
    }
}

int main(){
    int n;
    cin>>n;
    CTSIZE = n;
    PRE[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>ORGS[i];
        PRE[i] = PRE[i-1] + ORGS[i];
    }
    init();
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        cout<<sum(y)-sum(x-1)<<endl;
    }
    cin.ignore();
    cin.get();
}