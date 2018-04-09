//
// Created by zsh_o on 2018/4/9.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXSIZE = 200000+10;

struct Node{
    int x;
    int index;
};

Node NodeList[MAXSIZE];
int F[MAXSIZE];

bool cmp(Node a, Node b){
    return a.x < b.x; // < 为升序
}

int M,N;
int main(){
    cin>>N>>M;
    int t = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>NodeList[t].x;
            NodeList[t].index = i;
            t++;
        }
    }

    sort(NodeList, NodeList + M*N, cmp);
    memset(F, 0xff, sizeof(F));

    t = 0;
    for(int i=0; i<M*N && t<N; i++){
        Node n = NodeList[i];
        if(F[n.index] == -1){
            F[n.index] = n.x;
            t++;
        }
    }
    int mma = -1e9, mmi = 1e9;
    for(int i=0; i<N; i++){
        mma = max(mma, F[i]);
        mmi = min(mmi, F[i]);
    }
    int res = mma - mmi;
    for(int i=t; i<M*N; i++){
        Node n = NodeList[i];
        F[n.index] = n.x;
        mmi = 1e9;
        for(int j=0; j<N; j++){
            if(j==n.index)
                continue;
            mmi = max(mmi, n.x - F[j]);
        }
        res = min(res, mmi);
    }
    cout<<res<<endl;
    cin.get();
}