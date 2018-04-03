//
// Created by zsh_o on 2018/4/1.
//

#include <iostream>
using namespace std;

const int MAXSIZE = 1000+1;

int preTable[MAXSIZE];
int inTable[MAXSIZE];
int preIndex[MAXSIZE];
int inIndex[MAXSIZE];
int N;
struct Node{
    int pi, pj;
    int ii, ij;
    int root;
    Node *left, *right;
    Node(int _pi, int _pj, int _ii, int _ij):pi(_pi),pj(_pj),ii(_ii),ij(_ij){
        root = preTable[pi];
        left = NULL;
        right = NULL;
    }
};

void build(Node *p){
    int root = p->root;
    //构建左孩子区间
    if(p->pi<p->pj){
        int lij = inIndex[root] - 1;
        int lii = p->ii;
        int rij = p->ij;
        int rii = inIndex[root] + 1;

        int rlenth = rij - rii + 1;
        int lpi = preIndex[root] + 1;
        int rpj = p->pj;
        int lpj = rpj - rlenth;
        int rpi = lpj + 1;
        if(lii<=lij && lpi<=lpj){
            p->left = new Node(lpi, lpj, lii, lij);build(p->left);
        }
        if(rii<=rij && rpi<=rpj){
            p->right = new Node(rpi, rpj, rii, rij);build(p->right);
        }
    }
}

Node *queue[MAXSIZE];
int qi,qj;

void levelTrav(Node *root){
    qi = 0;
    qj = 1;
    queue[qi] = root;
    Node *p;
    while((qj+MAXSIZE-qi)%MAXSIZE!=0){
        p = queue[qi];
        qi = (qi+1)%MAXSIZE;
        cout<<p->root<<" ";

        if(p->left!=NULL){
            queue[qj] = p->left;
            qj = (qj+1)%MAXSIZE;
        }
        if(p->right!=NULL){
            queue[qj] = p->right;
            qj = (qj+1)%MAXSIZE;
        }
    }

}

int main(){
    cin>>N;
    int a;
    for(int i=1; i<=N; i++){
        cin>>a;
        preTable[i] = a;
        preIndex[a] = i;
    }
    for(int i=1; i<=N; i++){
        cin>>a;
        inTable[i] = a;
        inIndex[a] = i;
    }
    Node *root = new Node(1, N, 1, N);
    build(root);
    levelTrav(root);
}