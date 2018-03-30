//
// Created by zsh_o on 2018/3/27.
//

#include <iostream>

using namespace std;
typedef long long ll;

const int MAXSIZE = 100000+1;
int N,M;

ll D[MAXSIZE];
ll P[MAXSIZE];

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>D[i];
        cin>>P[i];
    }
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(D[i]>D[j]){
                ll temp = D[i];
                D[i] = D[j];
                D[j] = temp;
                temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }
    int a;
    for(int i=0; i<M; i++){
        cin>>a;
        int index = -1;
        for(int j=0; j<N; j++){
            if(D[j]>a){
                index = j;
                break;
            }
        }
        if(index==0)
            cout<<P[0]<<endl;
        else if(index<0){
            cout<<P[N-1]<<endl;
        }else{
            cout<<P[index-1]<<endl;
        }
    }
}