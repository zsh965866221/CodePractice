//
// Created by zsh96 on 2018/3/18.
//

#include <iostream>
#include <set>

using namespace std;

int get_K(char a, char b){
    return (b - a + 26) % 26;
}
set<string> S;
int main(){
    int N;
    cin>>N;
    string s;
    int k;
    for(int i=0; i<N; i++){
        cin>>s;
        k = get_K(s[0], 'A');
        s[0] = 'A';
        for(int j=1; j<s.size(); j++){
            s[j] = 'A' + (s[j] + k) % 26;
        }
        S.insert(s);
    }
    cout<<S.size()<<endl;
}