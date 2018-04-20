//
// Created by zsh96 on 2018/4/20.
//

#include <iostream>

using namespace std;
int levelN(int n){
    int i=0;
    while(n%10!=0){
        i++;
        n = n%10;
    }
}
int main(){
    cout<<levelN(131)<<endl;
}