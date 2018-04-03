//
// Created by zsh_o on 2018/4/1.
//

#include <iostream>
#include <map>

using namespace std;
typedef long long ll;
map<char, char> maps;

// value = 1 + 2^k_1 + 2^k_2 + ..., 代表变换的次数
char div_2(ll index){
    ll sum = 1;
    char ci = 'h';
    int k;
    while(sum!=index){
        k = 0;
        while(sum+(1<<k) <= index){
            k++;
        }
        sum += (1<<(k-1));
        ci = maps[ci];
    }
    return ci;
}

ll minLog_2(ll value){
    int k = 0;
    while((value>>k)>1){
        k++;
    }
    return 1<<k;
}

char solve_1(ll value){
    ll sum = 1;
    char ci = 'h';
    while(sum<value){
        ll sub = value - sum;
        sub = minLog_2(sub);
        sum += sub;
        ci = maps[ci];
    }
    return ci;
}

ll T, K;
int main(){
    maps['h'] = 'i';
    maps['i'] = 'o';
    maps['o'] = 'h';

    cin>>T;
    for(int i=0; i<T; i++){
        cin>>K;
        cout<<solve_1(K)<<endl;
    };
    cin.get();
};