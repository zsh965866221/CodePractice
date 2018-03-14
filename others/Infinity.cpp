//
// Created by zsh_o on 2018/3/14.
//

/*
 * 无穷大
 * 可以使用INT_MAX和INT_MIN，定义在limits.h
 * */

#include <iostream>
#include <cstring>

using namespace std;
const int MAXSIZE = 1000;
int A[MAXSIZE];

const int MY_INT_MAX = 0x7fffffff;
const int MY_INT_MIN = 0x80000000;

int main(){
    memset(A, INT_MAX, MAXSIZE);
    cout<<INT_MAX<<endl;
    cout<<INT_MIN<<endl;

    cout<<MY_INT_MAX<<endl;
    cout<<MY_INT_MIN<<endl;
}
