//
// Created by zsh96 on 2018/3/2.
//
#include <iostream>
#include <map>

using namespace std;
struct Node{};

int main(){
    map<char,Node*> tmap;
    tmap['a'] = new Node();
    auto a=tmap['b'];
    cout<<tmap['a']<<","<<tmap['b']<<endl;
}