//
// Created by zsh_o on 2018/4/9.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> ShortestM;
map<int, int> Path;

int main(){
    int start, end;
    cin>>start>>end;
    ShortestM[start] = 0;
    int a, b, v;
    while(cin>>a>>b>>v){
        int t = ShortestM[a] + v;
        if(ShortestM[b]==NULL || t < ShortestM[b]){
            ShortestM[b] = t;
            Path[b] = a;
        }
    }
    vector<int> L;
    int t = end;
    L.push_back(t);
    while(t!=start){
        t = Path[t];
        L.push_back(t);
    }
    for(int i=L.size()-1; i>0; i--){
        cout<<L[i]<<"->";
    }
    cout<<end<<"("<<ShortestM[end]<<")"<<endl;
//    cin.get();
}