//
// Created by zsh_o on 2018/3/6.
//

#include <iostream>
#include <vector>

using namespace std;

// Manacher算法（马拉车？）
int manacher(string s){
    if(s.size()<2){
        return s.size();
    }
    //开头添加$，用于检测回文串的时候截断，不越界
    string S;
    S.reserve(s.size() * 2 + 2);
    S.push_back('#');
    for(int i=0;i<s.size();i++){
        S.push_back(s[i]);
        S.push_back('#');
    }
    S.push_back('$');

    int P[S.size()];
    int rb = 0, id = 0, msize = 0;
    for(int i=0;i<S.size();i++){
        P[i] = i<rb? min(P[2 *id - i], rb - i) : 1;
        while(S[i-P[i]] == S[i+P[i]])
            P[i]++;
        if(i + P[i] > rb){
            id = i;
            rb = i + P[i];
        }
        msize = max(P[i], msize);
    }
    return msize - 1;
}

int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        cout<<manacher(s)<<endl;
    }
    cin.ignore();
    cin.get();
}