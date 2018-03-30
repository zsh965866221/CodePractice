//
// Created by zsh_o on 2018/3/14.
//

/*
 * 无穷大
 * 可以使用INT_MAX和INT_MIN，定义在limits.h
 * */

#include <iostream>
#include <cstring>
#include <limits>

using namespace std;
const int MAXSIZE = 1000;
int A[MAXSIZE];
int B[MAXSIZE];

const int MY_INT_MAX = 0x7fffffff;
const int MY_INT_MIN = 0x80000000;

int main(){
    cout<<INT_MAX<<endl; //2147483647
    cout<<INT_MIN<<endl; //-2147483648

    cout<<MY_INT_MAX<<endl; //2147483647
    cout<<MY_INT_MIN<<endl; //-2147483648

    memset(A, 0x7f, sizeof(A));
    memset(B, 0x80, sizeof(B));
    printf("%d\n", A[0]); //2139062143
    printf("%d\n", B[0]); //-2139062144
}
