//
// Created by zsh_o on 2018/4/2.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE = 100000+1;
typedef long lg;
lg A[MAXSIZE];
lg B[MAXSIZE];

int main(){
    memset(A, 0x00, sizeof(A));
    int nA;
    cin>>nA;
    for(int i=0; i<nA+1; i++){
        cin>>A[i];
    }
    int nB;
    cin>>nB;
    for(int i=0; i<nB+1; i++){
        cin>>B[i];
    }
    if(A[0]>B[0]){
        cout<<">"<<endl;
        return 0;
    }else if(A[0]<B[0]){
        cout<<"<"<<endl;
        return 0;
    }else{
        for(int i=1; i<max(nA, nB)+1; i++){
            if(A[i]>B[i]){
                if(A[0]>=0){
                    cout<<"<"<<endl;
                    return 0;
                }else if(A[0]<0){
                    cout<<">"<<endl;
                    return 0;
                }
            }else if(A[i]<B[i]){
                if(A[0]>=0){
                    cout<<">"<<endl;
                    return 0;
                }else if(A[0]<0){
                    cout<<"<"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"="<<endl;
    return 0;
}