//
// Created by zsh_o on 2018/4/2.
//

#include <iostream>
using namespace std;

const int MAXSIZE = 1e5+1;
string List;

int main(){
    getline(cin,List);
    int N = List.size();

    int left = 0;
    int right = 0;
    int index = 0;
    for(int i=0; i<N; i++){
        if(List[i]!='E'){
            right++;
        }
    }
    int curMin = right;
    for(int i = 0; i<N; i++){
        if(List[i] == 'E'){
            left++;
            continue;
        }else{
            right--;
        }
        curMin = min(curMin, left+right);
    }
    cout<<curMin<<endl;
}