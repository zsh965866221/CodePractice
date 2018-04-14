//
// Created by zsh_o on 2018/4/9.
//

#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    ll N;
    for(int i=0; i<t; i++) {
        cin >> N;
        if (N % 2 != 0) {
            cout << "No" << endl;
        } else {
            ll X = N;
            ll Y = 1;
            while (X % 2 == 0) {
                X = X / 2;
                Y = Y << 1;
            }
            cout<<X<<" "<<Y<<endl;
        }
    }
    cin.get();
}