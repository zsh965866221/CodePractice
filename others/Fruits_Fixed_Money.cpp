//
// Created by zsh96 on 2018/3/10.
//

#include <iostream>
using namespace std;

const int MAXN = 5000;
int N;
int MONEY;
int Weights[MAXN];
int Plan[MAXN];

void printPlan(int n){
    for(int i=1; i<=n; i++){
        if(Plan[i] == 0)
            continue;
        cout<<i<<" "<<Plan[i]<<" ";
    }
    cout<<endl;
}

void search(int n, int current_money){
    if(current_money == MONEY){
        printPlan(n);
        return;
    }
    if(n>=N){
        return;
    }
    for(int i=0; i*Weights[n+1]+current_money<=MONEY; i++){
        Plan[n+1] = i;
        search(n+1, current_money+i*Weights[n+1]);
    }
}

int main(){
    cin>>N;
    Weights[0] = 0;
    Plan[0] = 0;
    for(int i=1; i<=N; i++){
        cin>>Weights[i];
    }
    cin>>MONEY;
    search(0, 0);
    cin.ignore();
    cin.get();
}