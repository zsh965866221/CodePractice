//
// Created by zsh_o on 2018/4/9.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> string2int(string s){
    vector<int> res;
    res.push_back(0);
    int T = 0;
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i])){
            T *= 10;
            T += (s[i] - '0');
        }else if(s[i] == ',' || s[i] == '}'){
            res.push_back(T);
            T = 0;
        }
    }
    return res;
}

int main(){
    string line;
    getline(cin, line);
    vector<int> count = string2int(line);
    getline(cin, line);
    vector<int> value = string2int(line);
    int N = count.size();
    long sum = 0;
    for(int i=0; i<N; i++){
        sum += (count[i] * value[i]);
    }
    int t = sum>>1;
    long F[N][t+1]; //F[i][j]：选择前i个战斗力为j的个数
    memset(F, 0x00, sizeof(F));
    F[0][0] = 1;
    for(int i=1; i<N; i++){
        for(int j=0; j<=t; j++){
            int c = j/value[i];
            for(int k=0; k<=c && k<=count[i]; k++){
                F[i][j] += F[i-1][j-k*value[i]];
            }
        }
    }
    cout<<F[N][t]<<endl;
    cin.get();
}