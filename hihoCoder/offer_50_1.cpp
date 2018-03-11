//
// Created by zsh_o on 2018/3/11.
//

#include <iostream>
using namespace std;

const int MAXSIZE = 1000000+1;
int N;
int A[MAXSIZE];
int forwardSUM[MAXSIZE];
int prevSUM[MAXSIZE];

int main(){
    cin>>N;
    A[0] = 0;
    for(int i=1; i<=N; i++){
        cin>>A[i];
    }

    forwardSUM[0] = 0;
    prevSUM[N+1] = 0;
    int min_i;
    int min_sum = 0;
    for(int i=1; i<=N; i++){
        forwardSUM[i] = forwardSUM[i-1] + A[i];
        if(forwardSUM[i]<min_sum){
            min_sum = forwardSUM[i];
            min_i = i;
        }
        int j = N-i+1;
        prevSUM[j] = prevSUM[j+1] + A[j];
    }
    if(prevSUM[1]<=0)
        cout<<-1<<endl;
    bool finded = false;
    for(int i=N; i>=1 ;i--){
        if(prevSUM[i]>-min_sum && i>min_i){
            cout<<i<<endl;
            finded = true;
            break;
        }
    }
    if(!finded)
        cout<<-1<<endl;
    cin.ignore();
    cin.get();
}