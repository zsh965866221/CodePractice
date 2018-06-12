/**
 * Created by zsh_o on 2018/6/12.
 *
 * 10 3
 * 25 36 4 55 71 18 0 71 89 65
 * */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXSIZE = 1e5;
int A[MAXSIZE];
int N;
int k;

void alg1();
void alg2();
void alg3();

int main(){
    cin>>N>>k;
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    alg1();
    alg2();
    alg3();
    cin.get();
}

void alg1(){
    bool marks[N];
    memset(marks, 0x00, sizeof(marks));
    for(int i=0; i<k; i++){
        int cmax = INT32_MIN;
        int index = -1;
        for(int j=0; j<N; j++){
            if(marks[j]){
                continue;
            }
            if(A[j]>cmax){
                cmax=A[j];
                index = j;
            }
        }
        marks[index] = true;
        cout<<cmax<<" ";
    }
    cout<<endl;
}
void alg2(){
    int cA[N];
    memcpy(cA, A, sizeof(cA));
    sort(cA, cA+N);
    for(int i=0; i<k; i++){
        cout<<cA[N-i-1]<<" ";
    }
    cout<<endl;
}
void alg3(){
    int Scores[100+1];
    memset(Scores, 0x00, sizeof(Scores));
    for(int i=0; i<N; i++){
        Scores[A[i]]++;
    }
    int t = 0, p = 100;
    while(t<3){
        if(Scores[p]>0){
            cout<<p<<" ";
            Scores[p]--;
            t++;
        }else{
            p--;
        }
    }
    cout<<endl;
}