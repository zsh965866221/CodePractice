//
// Created by zsh_o on 2018/4/3.
//

#include <iostream>
using namespace std;
int N,K;

typedef long long ll;

int main(){
    cin>>N>>K;
    ll sum = 0;
    for(int y=K+1; y<=N; y++){
        int k = N/y;
        sum += (y-K)*k;
        sum += max(0, N-k*y-max(0,K-1));
    }
    cout<<sum<<endl;
//    cin.get();
}