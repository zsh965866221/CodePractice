//
// Created by zsh96 on 2018/3/2.
//

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> GetNext(string s){
    vector<int> next(s.size()+1,0);
    next[0] = -1;
    next[1] = 0;
    for(int i=2;i<next.size();i++){
        int k = next[i-1];
        char c = s[i-1];
        while(k>-1 && c!=s[k]){
            k = next[k];
        }
        next[i] = k+1;
    }
    return next;
}
int search(string _s, string _t, vector<int> next){
    int total = 0;
    int n = 0;
    int np = 0;
    while(n<_s.size()){
        while(np>0 && _s[n]!=_t[np]){
            np = next[np];
        }
        if(_s[n]==_t[np])
            np++;
        n++;
        if(np==_t.size()){
            total++;
            np = next[np];
        }
    }
    return total;
}

int main(){
    int n;
    cin>>n;
    string s;
    string t;
    for(int i=0;i<n;i++){
        cin>>t;cin>>s;
        auto next = GetNext(t);
        cout<<search(s, t, next)<<endl;
    }
    cin.ignore();
    cin.get();
}
