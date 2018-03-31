//
// Created by zsh_o on 2018/3/2.
//

/**
 * 交换两个指针的指向
 * 函数的参数需要使用指针的指针
 * */

#include <iostream>

using namespace std;

int test(int **a, int **b){
    int *t = *a;
    cout<<"ex "<<t<<' '<<*a<<endl;
    *a = *b;
    cout<<"ex "<<*b<<' '<<*a<<endl;
    cout<<"ex "<<t<<' '<<*a<<endl;
    *b = t;
    return **a + **b;
}
int test(int &a, int &b){
    int *t = &a;
    cout<<"ex"<<t<<' '<<a<<endl;
    a = b;
    cout<<"ex"<<b<<' '<<a<<endl;
    b = *t;
    return a + b;
}

int main(){
    int *a = new int(1);
    int *b = new int(2);
    cout<<test(&a, &b)<<endl;
    cout<<*a<<" "<<*b<<endl;
}