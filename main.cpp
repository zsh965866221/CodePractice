//
// Created by zsh_o on 2018/3/2.
//
#include <iostream>

using namespace std;

int test(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
    return a + b;
}


int main(){
    int a = 1;
    int b = 2;
    cout<<test(a, b)<<endl;
    cout<<a<<" "<<b<<endl;
}