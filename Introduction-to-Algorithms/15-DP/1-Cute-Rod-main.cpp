//
// Created by zsh_o on 2018/4/5.
//

/*
10
1 5 8 9 10 17 17 20 24 30
10 8 5

30 22 13
 * */

#include <iostream>
using namespace std;

const int MAXSIZE = 100+1;
int N, M;
int P[MAXSIZE];


#include "1-Cute-Rod-1.h"
#include "1-Cute-Rod-2.h"
#include "1-Cute-Rod-3.h"
#include "1-Cute-Rod-4.h"
#include "1-Cute-Rod-my.h"


int main(){
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>P[i];
    }

    while(cin>>M){
        cout<<Cute_Rod(P, M)<<endl;
        cout<<Cute_Rod_My(P, M)<<endl;
        cout<<Memoized_Cut_Rod(P, M)<<endl;
        cout<<Bottom_Up_Cut_Rod(P, M)<<endl;
        cout<<Extended_Bottom_Up_Cut_Rod(P, M)<<endl;
    }
}