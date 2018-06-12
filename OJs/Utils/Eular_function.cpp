//
// Created by zsh96 on 2018/4/25.
//

/**
 * 欧拉函数
 * oula(n) = x(1-1/p1)(1-1/p2)(1-1/p3)...(1-1/pN)
 * */

#include <iostream>
#include <cstring>

using namespace std;

int eular(int n){
    int res = n;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            res = res - res/i;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1){
        res = res - res/n;
    }
    return res;
}

// 打表
// 让整个列表分别除以素数（每个素数只除以一遍）
const int MAXSIZE = 1e5+1;
int Euler[MAXSIZE];
void init(){
    for(int i=1; i<MAXSIZE; i++){
        Euler[i] = i;
    }
    for(int i=2; i<MAXSIZE; i++){
        if(Euler[i]==i){ // 判断i为素数，因为i已经除以了之前的所有素数，如果i不变，i同样为素数
            for(int j=i; j<MAXSIZE; j+=i){
                Euler[j] -= Euler[j]/i;
            }
        }
    }
}

//线性筛法，在线性筛选素数的基础上进行
int prime[MAXSIZE];
bool check[MAXSIZE];
void linearEularTable(){
    memset(prime, 0x00, sizeof(prime));
    memset(check, 0x00, sizeof(check));
    memset(Euler, 0x00, sizeof(Euler));
    Euler[1] = 1;
    int index = 0;
    for(int i=2; i<MAXSIZE; i++){
        if(!check[i]){ // i is prime, phi(i) = i-1
            prime[index++] = i;
            Euler[i] = i-1;
        }
        for(int j=0; j<index; j++){
            int t = i * prime[j];
            if(t>MAXSIZE){
                break;
            }
            check[t] = true;
            if(i%prime[j]==0){ // if i%p==0, phi(i*p) = phi(i) * p // p is prime
                Euler[t] = Euler[i] * prime[j];
                break;
            }else{ // i%p!=0, phi(i*p) = phi(i) * (p-1)
                Euler[t] = Euler[i] * (prime[j] - 1);
            }
        }

    }
}

int main(){
    linearEularTable();
    cout<<eular(8)<<endl;
}