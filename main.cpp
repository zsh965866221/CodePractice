//
// Created by zsh_o on 2018/3/2.
//
#include <iostream>
#include <map>
#include <cmath>

using namespace std;
int log2(int x){
    int n = 0;
    while((1<<n)<=x){
        n++;
    }
    return n-1;
}
int main(){
    int k = 1e6+1;
    int a = log2(k);
    cout<<k<<endl;
    cout<<a<<endl;
}