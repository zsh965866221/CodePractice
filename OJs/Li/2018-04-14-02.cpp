//
// Created by zsh_o on 2018/4/14.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE = 1000000+1;
int N;
int A[MAXSIZE];
int B[MAXSIZE];
int T;
int main(){
    memset(A, 0x00, sizeof(A));
    memset(B, 0x00, sizeof(B));
    cin>>N;
    T = 0;
    int a ,b ,c , d;
    for(int i=0; i<N; i++){
        cin>>a;
        if(a==1){
            cin>>b>>c>>d;
            for(int j=b; j<=c; j++){
                if(A[j]==0){
                    A[j] = d;
                }else{
                    A[j] = max(A[j], d);
                }
            }
        }else if(a==2){
            cin>>b>>c;
            B[b] += c;
        }
        T = max(c, T);
    }
    int res = 0;
    for(int i=1; i<=T; i++){
        res += (A[i]+B[i]);
    }
    cout<<res<<endl;
//    cin.get();
}