//
// Created by zsh96 on 2018/5/3.
//

//素数判定

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool prime_1(int n){
    for(int i=2; i<n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

bool prime_2(int n){
    for(int i=2; i<sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

const int MAXSIZE = 1e5+1;
int prime[MAXSIZE];
bool check[MAXSIZE];
void prime_3(){
    memset(prime, 0x00, sizeof(prime));
    memset(check, 0x00, sizeof(check));
    int index = 0;
    for(int i=2; i<MAXSIZE; i++){
        if(!check[i]){ //i is prime
            prime[index++] = i;
            for(int j=i+i; j<MAXSIZE; j+=i){
                check[j] = true;
            }
        }
    }
}

//linear
void prime_4(){
    memset(prime, 0x00, sizeof(prime));
    memset(check, 0x00, sizeof(check));
    int index = 0;
    for(int i=2; i<MAXSIZE; i++){
        if(!check[i]){
            prime[index++] = i;
        }
        for(int j=0; j<index; j++){
            int t = i * prime[j];
            if(t>MAXSIZE)
                break;
            check[t] = true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}

int main(){
    prime_4();
    cout<<endl;
}