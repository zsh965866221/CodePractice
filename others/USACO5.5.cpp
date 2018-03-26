//
// Created by zsh_o on 2018/3/26.
//

#include <iostream>
using namespace std;

string S;
int N;

int main(){

    cin>>S;
    N = S.size();

    int i = 0,j = 1, k;
    while(i<N && j<N){
        k = 0;
        while(S[(i+k)%N] == S[(j+k)%N])
            k++;
        if(k>=N)
            return min(i, j);
        if(S[(i+k)%N] > S[(j+k)%N])
            i += (k + 1);
        else
            j += (k + 1);
        if(i == j)
            j++;
    }
    cout<<min(i, j)<<endl;
    cin.get();
}