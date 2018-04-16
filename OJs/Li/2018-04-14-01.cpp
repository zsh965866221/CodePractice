//
// Created by zsh_o on 2018/4/14.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long ll;
int N, K;
vector<int> A;
int main(){
    cin>>N>>K;
    int a;
    for(int i=0; i<N; i++){
        cin>>a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    for(int i=0; i<K-1; i++){
        cout<<A[i]<<",";
    }
    cout<<A[K-1]<<endl;
//    cin.get();
}