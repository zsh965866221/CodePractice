//
// Created by zsh96 on 2018/2/26.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TriNode{
    int count;
    map<char, TriNode *> children;
    TriNode():count(1){}
};

class Tri{
    TriNode* root;
public:
    Tri():root(new TriNode()){ }
    ~Tri(){ }
    void add(string word){
        TriNode* p = root;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(p->children[c] != NULL){
                p->children[c]->count++;
            }else{
                p->children[c] = new TriNode();
            }
            p = p->children[c];
        }
    }

    int prefix(string word){
        TriNode* p = root;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(p->children[c] != NULL){
                p = p->children[c];
            }else{
                return 0;
            }
        }
        return p->count;
    }
};

Tri tri;

int main(){
    int n;
    cin>>n;
    string word;
    for(int i=0;i<n;i++){
        cin>>word;
        tri.add(word);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>word;
        cout<<tri.prefix(word)<<endl;
    }
    cin.ignore();
    cin.get();
}
