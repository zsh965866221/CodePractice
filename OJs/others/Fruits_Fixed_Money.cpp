//
// Created by zsh_o on 2018/3/10.
//

/*
Suppose you have n dollars, and you need to spend it all to buy fruits of varing prices.

For example, if you have 500 dollars to spend on the following fruits:

banana 32
kiwi 41
mango 97
papaya 254
pineapple 399

then you can get 2 combinations

6 kiwis, 1 papaya
7 bananas, 2 kiwis, 2 mangos

write a program that takes a dollar amount, and output all possible combinations of fruits the amount of money can buy.
Note, assume the money must be spent up based on the following fruits products:

apple 59
banana 32
coconut 155
grapefruit 128
jackfruit 1100
kiwi 41
lemon 70
mango 97
orange 73
papaya 254
pear 37
pineapple 399
watermelon 500
 * */

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