//
// Created by zsh_o on 2018/3/23.
//

/*
 * http://exercise.acmcoder.com/online/online_judge_ques?ques_id=3819&konwledgeId=40
 * */

#include <iostream>

using namespace std;

typedef long long ll;

ll N,M,K;

// 统计不大于value的个数，只需要统计每一行即可
ll le_value(ll value){
    ll num = 0;
    for(ll i=1; i<=M; i++){
        num += (value/i)>N? N : value/i;
    }
    return num;
}

ll search(ll left, ll right, ll kth){
    ll mid;
    while(left <= right){
        mid = (left+right)/2;
        ll v = le_value(mid);
        if(v == kth){
            return mid;
        }else if(kth < v){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    cin>>N>>M>>K;
    cout<<search(1, N*M, K)<<endl;
//    cin.get();
}