//
// Created by zsh_o on 2018/4/9.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE = 50+1;
int N;
int counts[MAXSIZE];
int used[MAXSIZE];
string S;
bool isH(){
    int i = 0;
    int j = N-1;
    while(i<j){
        if(used[i]!=-1){
            i++;
            continue;
        }
        if(used[j]!=-1){
            j--;
            continue;
        }
        if(S[i]==S[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}

int search(int d){
    if(d==1){
        return 1;
    }
    int t = 0;
    if(isH()){
        t++;
    }
    char pre = '~';
    for(int i=0; i<N; i++){
        if(used[i]!=-1 || S[i]==pre)
            continue;
        pre = S[i];
        used[i] = 1;
        t += search(d-1);
        used[i] = -1;
    }
    return t;
}

int main(){
    getline(cin, S);
    N = S.size();
    memset(used, 0xff, sizeof(used));
    cout<<search(N)<<endl;
    cin.get();
}
