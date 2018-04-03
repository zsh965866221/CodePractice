//
// Created by zsh_o on 2018/4/1.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAXSIZE = 1000+1;
struct Node{
    string name;
    vector<Node *> children;
    bool deathed;
    Node(string _name) : name(_name), deathed(false){

    }
};
map<string, Node *> maps;

void birth(string _parent, string _child){
    Node *_p = maps[_parent];
    Node *_c = new Node(_child);
    maps[_child] = _c;
    _p->children.push_back(_c);
}
void death(string _name){
    maps[_name]->deathed = true;
}

Node *stack[MAXSIZE];
int sp = -1;
void preOrder(Node *root){
    sp++;
    stack[sp] = root;
    Node *p;
    while(sp>-1){
        p = stack[sp];
        sp--;
        if(!p->deathed){
            cout<<p->name<<endl;
        }

        for(int i=p->children.size()-1; i>=0; i--){
            sp++;
            stack[sp] = p->children[i];
        }
    }
}

int N;
string state, parent, child;
string king;

int main(){

    cin>>N>>king;
    maps[king] = new Node(king);
    maps[king]->deathed = true;
    for(int i=0; i<N; i++){
        cin>>state;
        if(state[0]=='b'){
            cin>>parent>>child;
            birth(parent, child);
        }else{
            cin>>parent;
            death(parent);
        }
    }
    preOrder(maps[king]);
    cin.get();
}