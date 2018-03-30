//
// Created by zsh_o on 2018/3/25.
//

/**
 * in:
 *  5
 *  bdceafghijklmnopqrstuvwxyz
 *  abcde
 *  adc
 *  cda
 *  cad
 *  ddc
 * out:
 *  ddc
 *  cda
 *  cad
 *  abcde
 *  adc
 * */

#include <iostream>
#include <vector>

using namespace std;

int DictTable[26];
int get_order(char c){
    return DictTable[c-'a'];
}
int N;

bool stringCompare(string &sa, string &sb){
    for(int i=0; i<min(sa.size(), sb.size()); i++){
        int ta = get_order(sa[i]);
        int tb = get_order(sb[i]);
        if(ta < tb)
            return true;
        else if(ta > tb){
            return false;
        }
    }
    return sa.size() > sb.size();
}

vector<string *> SL;

void exchange(string **a, string **b){
    string *t = *a;
    *a = *b;
    *b = t;
}
void S_order(vector<string *> &pSL){
    for(int i=0; i<pSL.size(); i++){
        for(int j=i+1; j<pSL.size(); j++){
            if(stringCompare(*pSL[j], *pSL[i])){
                exchange(&pSL[i], &pSL[j]);
            }
        }
    }
}

int main(){
    cin>>N;
    char c;
    for(int i=0; i<26; i++){
        cin>>c;
        DictTable[c-'a'] = i;
    }
    for(int i=0; i<N; i++){
        string *s = new string;
        cin>>*s;
        SL.push_back(s);
    }
    S_order(SL);
    for(int i=0; i<SL.size(); i++){
        cout<<*SL[i]<<endl;
    }
    cin.get();
}