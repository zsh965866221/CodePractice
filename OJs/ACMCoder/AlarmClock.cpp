//
// Created by zsh_o on 2018/4/3.
//

#include <iostream>
using namespace std;

const int MAXN = 100;
int N;
int alarms[MAXN];
int Tuse;
int TClass;

void printT(int m){
    cout<<m/60<<" "<<m%60<<endl;
}

int main(){
    cin>>N;
    int a,b;
    for(int i=0; i<N; i++){
        cin>>a>>b;
        alarms[i] = a*60+b;
    }
    cin>>Tuse;
    cin>>a>>b;
    TClass = a*60+b;

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(alarms[j]<alarms[i]){
                alarms[i] = alarms[i]^alarms[j];
                alarms[j] = alarms[i]^alarms[j];
                alarms[i] = alarms[i]^alarms[j];
            }
        }
    }

    //考虑晚上上课的情况
    bool turned = false;
    int t = TClass - Tuse;
    if(t<0){
        turned = true;
        t += 24*60;
    }

    if(!turned){
        for(int i=0; i<N-1; i++){
            if(alarms[i]<=t && alarms[i+1]>t){
                printT(alarms[i]);
                return 0;
            }
        }
        printT(alarms[N-1]);
        return 0;
    }else{
        for(int i=N-1; i>0; i--){
            if(alarms[i-1]<alarms[i] && alarms[i]>=t){
                printT(alarms[i]);
                return 0;
            }
        }
        printT(alarms[0]);
        return 0;
    }
//    cin.get();
}