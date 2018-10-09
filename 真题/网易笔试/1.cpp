#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
long long n;
long long res;
long long n1, n2;
long long m;
long long t;
int main(){
    cin>>n;
    m = 1;
    while(true){
        n1 = 0;
        n2 = 0;
        res = n;
        while(res>0){
            t = res < m ? res : m;
            n1 += t;
            res -= t;
            t = res / 10;
            n2 += t;
            res -= t;
        }
        if(n1 > n2){
            printf("%d\n", m);
            break;
        }
        m++;
    }
}
