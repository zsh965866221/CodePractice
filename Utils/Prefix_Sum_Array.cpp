//
// Created by zsh96 on 2018/3/9.
//
/*
 * 一维：
 * s[i] = a[1] + a[2] + ... + a[i]
 *
 * n个数，q次询问，每次询问一个区间[x, y]的和
 * */

#include <iostream>

using namespace std;

int PSUM[100000];
int main(){
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        int n,m;
        cin>>n>>m;
        int a;
        PSUM[0] = 0;
        for(int ni=1; ni<=n; ni++){
            cin>>a;
            PSUM[ni] = PSUM[ni-1] + a;
        }
        for(int mi=0; mi<m; mi++){
            int a,b;
            cin>>a>>b;
            cout<<PSUM[max(a,b)]-PSUM[min(a,b)-1]<<endl;
        }
    }
    cin.ignore();
    cin.get();
}
