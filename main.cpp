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
    int value;
    while(cin>>value){
        int sum = 0;
        while(sum<value){
            int sub = value - sum;
            sub = minLog_2(sub);
            cout<<sub<<endl;
            sum += sub;
        }
    }
}