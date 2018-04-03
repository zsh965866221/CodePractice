//
// Created by zsh_o on 2018/4/3.
//

/**
 * 二维线段树的方法会超时
 * */

#include <iostream>
#include <algorithm>

using namespace std;

int MAXN = 1e9;
const int MAXSIZE = 50;
int T;
int X1[MAXSIZE], Y1[MAXSIZE];
int X2[MAXSIZE], Y2[MAXSIZE];

int TX[MAXSIZE*2];
int TY[MAXSIZE*2];
int main(){
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>X1[i];
    }
    for(int i=0; i<T; i++){
        cin>>Y1[i];
    }
    for(int i=0; i<T; i++){
        cin>>X2[i];
    }
    for(int i=0; i<T; i++){
        cin>>Y2[i];
    }
    for(int i=0; i<T; i++){
        TX[i] = X1[i];
        TY[i] = Y1[i];
    }
    for(int i=T; i<2*T; i++){
        TX[i] = X2[i-T];
        TY[i] = Y2[i-T];
    }

    for(int i=0; i<2*T; i++){
        for(int j=i+1; j<2*T; j++){
            if(TX[i]>TX[j]){
                TX[i] = TX[i]^TX[j];
                TX[j] = TX[i]^TX[j];
                TX[i] = TX[i]^TX[j];
            }
            if(TY[i]>TY[j]){
                TY[i] = TY[i]^TY[j];
                TY[j] = TY[i]^TY[j];
                TY[i] = TY[i]^TY[j];
            }
        }
    }
    int tx = 0;
    int ty = 0;
    for(int i=1; i<2*T; i++){
        if(TX[i]!=TX[tx]){
            TX[tx+1] = TX[i];
            tx++;
        }
        if(TY[i]!=TY[ty]){
            TY[ty+1] = TY[i];
            ty++;
        }
    }
    int res = 0;
    for(int i=0;i<=tx; i++){
        for(int j=0; j<=ty; j++){
            int tem = 0;
            for(int k=0; k<T; k++){
                if(X1[k]<=TX[i] && Y1[k]<=TY[j] && X2[k]>TX[i] && Y2[k]>TY[j]){
                    tem++;
                }
            }
            res = max(res, tem);
        }
    }

    cout<<res<<endl;
    cin.get();
}