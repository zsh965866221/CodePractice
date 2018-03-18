//
// Created by zsh96 on 2018/3/18.
//

#include <iostream>

using namespace std;

int main(){
    int N, M, X, Y;
    int A, B, C, D;
    cin>>N>>M>>X>>Y;
    cin>>A>>B>>C>>D;


    printf("%d\n", min((N-X)/A, (M-Y)/B) + min((N-X)/C, (M-Y)/D) +1);
}