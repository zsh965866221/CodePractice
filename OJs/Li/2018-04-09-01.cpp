//
// Created by zsh_o on 2018/4/9.
//

/**
 * 题目大意是，一个串删掉若干个字符之后变成回文串，问，一共有多少种删法，空串不是回文串，相同删除顺序的算是一种
 * */

#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE = 50+5;
string S;
int N;
typedef long long ll;
ll F[MAXSIZE][MAXSIZE];
int main(){
    getline(cin, S);
    N = S.size();
    memset(F, 0x00, sizeof(F));
    for(int i=1; i<=N; i++){
        for(int l=0; l+i-1<N; i++){
            int r = l + i - 1;
            F[l][r] += F[l+1][r];
            F[l][r] += F[l][r-1];
            if(S[l]==S[r])
                F[l][r] += 1;
            else
                F[l][r] -= F[l+1][r-1];
        }
    }
    cout<<F[0][N-1]<<endl;
    cin.get();
}
