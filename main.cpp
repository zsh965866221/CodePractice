//
// Created by zsh_o on 2018/3/2.
//
#include <iostream>

using namespace std;


int minLog_2(int value){
    int k = 0;
    while((value>>k)>1){
        k++;
    }
    return 1<<k;
}


int main(){
    int k = 7465536938;
    cout<<k;
}