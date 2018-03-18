//
// Created by zsh96 on 2018/3/18.
//
#include <iostream>
#include <vector>

using namespace std;

// TLE...

int get_K(char a, char b){
    return (b - a + 26) % 26;
}

bool similar(string a, string b){
    if(a.size() != b.size())
        return false;
    else{
        int k = get_K(a[0], b[0]);
        if(k<0){
            return false;
        }else{
            for(int i=1; i<a.size(); i++){
                if(k!=get_K(a[i], b[i])){
                    return false;
                }
            }
            return true;
        }
    }
}

vector<string> A;

int main(){
    int N;
    scanf("%d", &N);
    string s;
    for(int i=0; i<N; i++){
        cin>>s;
        if(A.size()==0){
            A.push_back(s);
        }else{
            int existed = false;
            for(int i=0; i<A.size(); i++){
                if(similar(A[i], s)){
                    existed = true;
                    break;
                }
            }
            if(!existed){
                A.push_back(s);
            }
        }
    }
    cout<<A.size()<<endl;
}