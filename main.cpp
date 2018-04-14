//
// Created by zsh_o on 2018/3/2.
//
#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

vector<int> str2int(string str) {
    vector<int> res;
    int num = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') continue;
        if(isdigit(str[i])) {
            num *= 10;
            num += str[i] - '0';
        }
        if(str[i] == ',' || i == str.length() - 1) {
            res.push_back(num);
            num = 0;
        }
    }
    return res;
}

int main() {
    // freopen("input.txt","r",stdin);
    string str;
    map<int,int> mp;
    while(getline(cin,str)) {
        mp.clear();
        int sum = 0;
        str = str.substr(1,str.length()-2);
        vector<int> cnt = str2int(str);

        getline(cin,str);
        str = str.substr(1,str.length() - 2);
        vector<int> val = str2int(str);

        for(int i = 0; i < cnt.size(); i++) {
            sum += val[i] * cnt[i];
            if(mp.count(val[i])) {
                mp[val[i]] += cnt[i];
            }
            else {
                mp[val[i]] = cnt[i];
            }
        }
        if(sum  % 2 ==1) {
            cout<<0<<endl;
            return 1;
        }
        cnt.clear();
        val.clear();
        cnt.push_back(0);
        val.push_back(0);
        map<int,int>::iterator it;
        for(it = mp.begin(); it != mp.end(); it++) {
            val.push_back(it->first);
            cnt.push_back(it->second);
        }

        int n = mp.size();
        int m = sum >> 1;
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m ; j++) {
                int c = j / val[i];
                for(int k = 0; k <= c && k <= cnt[i]; k++) {
                    dp[i][j] += dp[i-1][j-k*val[i]];
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
    cin.get();
    return 0;

}