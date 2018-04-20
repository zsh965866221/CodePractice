//
// Created by zsh96 on 2018/4/20.
//

#include <iostream>
using namespace std;

int T;
int n;
int e10(int n){
    int res = 10;
    while(--n){
        res *= 10;
    }
    return res;
}
int main(){
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>n;
        int levelN = 1;
        int t = n;
        int d = 10;
        long long sum = 0;
        while(t/10!=0){
            sum += (d*levelN);
            d *= 10;
            t /= 10;
            levelN++;
        }
        d /= 10;
        d = max(10, d);
        int res = n%d;
        sum += (res+1)*levelN;
        sum--;
        cout<<sum<<endl;
    }
    cin.get();
}