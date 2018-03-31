//
// Created by zsh_o on 2018/3/31.
//

/**
 * 三个数 排序
 * */

#include <iostream>
using namespace std;

void exchange(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

/**
 * 按位计算，只需要考虑四种情况即可
 * 第一步分为，两个相同，或不同
 * 第一个相同，a = a^b = 0, b = 0^b = b, b保持不变，a = 0^b = b = a
 * 第一个不同，a = a&b = 1, b = 1^b = ~b = a, b取逆并等于a，a = 1^b = 1^~b = 1^a = ~a = b
 * */
void exchange_1(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void order_1(int a, int b, int c){
    int mmin = min(min(a, b), c);
    int mmax = max(max(a, b), c);
    int middle = a + b + c - mmin - mmax;
    cout<<mmin<<" "<<middle<<" "<<mmax<<endl;
}

//前两个保证a最小，然后再比较剩余两个即可
void order_2(int a, int b, int c){
    int t;
    if(a>b){
//        t = a;
//        a = b;
//        b = t;
        exchange(a, b);
    }
    if(a>c){
//        t = a;
//        a = c;
//        c = t;
        exchange(a, c);
    }
    if(b>c){
//        t = b;
//        b = c;
//        c = t;
        exchange(b, c);
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
}

int main(){
    int a, b, c;
    while(cin>>a>>b>>c){
        order_1(a, b, c);
        order_2(a, b, c);
    }

}