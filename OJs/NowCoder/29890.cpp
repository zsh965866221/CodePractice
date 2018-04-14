//
// Created by zsh_o on 2018/4/9.
//

#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
const int MAXSIZE = 5e4+1;
char s[MAXSIZE];
int cnt;
int main(){
    scanf("%s %d", s, &cnt);
    int N = strlen(s);
    bool deleted[N];
    memset(deleted, 0x00, sizeof(deleted));
    for(int i=0; i<cnt; i++){
        char mint = CHAR_MAX;
        int mini = -1;
        for(int j=0; j<N; j++){
            if(!deleted[j] && s[j]<mint){
                mint = s[j];
                mini = j;
            }
        }
        deleted[mini] = true;
    }
    for(int i=0; i<N; i++){
        if(!deleted[i]){
            cout<<s[i];
        }
    }
    cout<<endl;
//    cin.get();
}