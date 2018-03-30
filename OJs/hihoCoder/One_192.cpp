//
// Created by zsh_o on 2018/3/6.
//

/*
 * 这个代码写的有点复杂，其实解法可以很简单
 * */

#include <iostream>
#include <map>

using namespace std;

struct Node{
    Node* prev;
    Node* next;
    bool existed;
    char value;
    Node(char c):prev(NULL),next(NULL),existed(false),value(c){}
};
map<char, Node*> TEM;

void setup(){
    for(char c='A';c<='Z';c++){
        TEM[c] = new Node(c);
    }
    for(char c='A';c<='Z';c++){
        Node* p = TEM[c];
        p->prev = TEM[c-1];
        p->next = TEM[c+1];
    }

    //删掉 'J'
    Node* p = TEM['J'];
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete(p);
}

int main(){
    setup();
    Node *root = TEM['A'];
    Node *troot = new Node('0');
    Node *ttail = troot;
    Node *p;
    string s;
    cin>>s;

    //把双向链表中的单词抽出来，插入到链尾
    for(int i=0;i<s.size();i++){
        char c = s[i];
        c = c=='J'? 'I':c;
        p = TEM[c];
        if(p->existed){
            continue;
        }
        p->existed = true;
        if(p->prev){
            p->prev->next = p->next;
        }
        if(p->next){
            p->next->prev = p->prev;
        }

        if(p == root){
            root = p->next;
        }

        p->prev = ttail;
        p->next = NULL;
        ttail->next = p;
        ttail = p;
    }
    ttail->next = root;
    if(root){
        root->prev = ttail;
    }

    int i=0;
    p = troot->next;
    while(p){
        cout<<p->value;
        if((i+1)%5==0)
            cout<<endl;
        p = p->next;
        i++;
    }

    cin.ignore();
    cin.get();
}

void solve_simple(){
    char table[25];
    bool used[26];
    used['J'-'A'] = true;
    string s;
    cin>>s;
    int k = 0;
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        c = c=='J'? 'I':c;
        if(!used[c-'A']){
            table[k] = c;
            used[c] = true;
            k++;
        }
    }
    for(char c='A'; c<='Z'; c++){
        if(!used[c-'A']){
            table[k] = c;
            used[c] = true;
            k++;
        }
    }
    for(int i=0; i<25; i++){
        cout<<table[i]<<' ';
        if(i%5==0){
            cout<<endl;
        }
    }
}