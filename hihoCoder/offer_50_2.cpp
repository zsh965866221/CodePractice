//
// Created by zsh_o on 2018/3/11.
//

#include <iostream>
using namespace std;

//区间，插入的时候修改区间值，左孩子和右孩子同时存在
struct Node{
    int i,j;
    int length;
    int max_length;
    Node *left;
    Node *right;
    Node(int _i, int _j):i(_i),j(_j),left(NULL),right(NULL){
        length = (j-i+1);
        max_length = 0;
    }
};
Node *root;
int N,M,K;

void insert(int value, Node *p){
    if(p->left){
        //判断value在哪个区间里面
        if(value>=p->left->i && value<=p->left->j){
            insert(value, p->left);
        }else{
            insert(value, p->right);
        }
        p->max_length = max(p->left->max_length, p->right->max_length);
    }else{
        p->left = new Node(p->i, value-1);
        p->right = new Node(value+1, p->j);
        p->left->max_length = p->left->length;
        p->right->max_length = p->right->length;
        p->max_length = max(p->left->max_length, p->right->max_length);
    }
}

int search_insert(Node *p){
    if(p->left){
        int k;
        if(p->left->max_length >= p->right->max_length){
            k = search_insert(p->left);
        }
        else{
            k =search_insert(p->right);
        }
        p->max_length = max(p->left->max_length, p->right->max_length);
        return k;
    }else{
        int value = (p->i+p->j)/2;
        p->left = new Node(p->i, value-1);
        p->right = new Node(value+1, p->j);
        p->left->max_length = p->left->length;
        p->right->max_length = p->right->length;
        p->max_length = max(p->left->max_length, p->right->max_length);
        return value;
    }
}

int main(){
    cin>>N>>M>>K;
    root = new Node(1, N);
    int a;
    for(int i=0; i<M; i++){
        cin>>a;
        insert(a, root);
    }
    for(int i=0; i<K; i++){
        cout<<search_insert(root)<<endl;
    }
    cin.ignore();
    cin.get();
}