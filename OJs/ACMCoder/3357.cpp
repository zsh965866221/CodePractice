//
// Created by zsh_o on 2018/4/9.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int value;
    int index;
    Node(int _v, int _i):value(_v),index(_i){}
};
vector<Node *> L;

bool cmp(Node *a, Node *b){
    return a->value < b->value;
}
bool cmp1(Node *a, Node *b){
    return a->index < b->index;
}
int main(){
    int N, K;
    cin>>N>>K;
    int t;
    for(int i=0; i<N; i++){
        cin>>t;
        L.push_back(new Node(t, i));
    }

    sort(L.begin(), L.end(), cmp);
    sort(L.begin(), L.begin() + K, cmp1);
    for(int i=0; i<K; i++){
        cout<<L[i]->value<<endl;
    }
//    cin.get();
}