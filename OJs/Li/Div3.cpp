//
// Created by zsh_o on 2018/3/27.
//

#include <iostream>
using namespace std;

typedef long long ll;

ll get_sum(ll x){
    return (1+x)*x/2;
}

bool divable_3(ll x){
    return x%3 == 0;
}

int main(){
    ll l,r;
    cin>>l>>r;
    int num = 0;
    for(ll i=l; i<=r; i++){
        if(divable_3(get_sum(i))){
            num++;
        }
    }
    cout<<num<<endl;
}