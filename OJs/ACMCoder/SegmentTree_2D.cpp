//
// Created by zsh_o on 2018/4/3.
//

#include <iostream>
#include <cstring>

using namespace std;

int MAXN = 1e9;
const int MAXSIZE = 50;
int T;
int X1[MAXSIZE], Y1[MAXSIZE];
int X2[MAXSIZE], Y2[MAXSIZE];

struct Node{
    int x1,y1,x2,y2;
    int value;
    int lazy;
    Node *part1, *part2, *part3, *part4;
    Node(int _x1, int _y1, int _x2, int _y2):x1(_x1),x2(_x2),y1(_y1),y2(_y2){
        value = 0;
        lazy = 0;
        part1 = part2 = part3 = part4 = NULL;
    }
};

int build(Node *cur, int x1, int y1, int x2, int y2){
    //当前区间在矩形区域内部
    if(cur->x1>=x1 && cur->y1>=y1 && cur->x2<=x2 && cur->y2<=y2){
        cur->value++;
        cur->lazy++;
        return cur->value;
    }
    //当前区域在举行区域外部
    if(cur->x2<=x1 || cur->x1>=x2 || cur->y2<=y1 || cur->y1>=y2){
        return -1;
    }
    if(cur->part1==NULL){
        cur->part1 = new Node(cur->x1, cur->y1, (cur->x1+cur->x2)/2, (cur->y1+cur->y2)/2);
    }
    if(cur->part2==NULL){
        cur->part2 = new Node((cur->x1+cur->x2)/2, cur->y1, cur->x2, (cur->y1+cur->y2)/2);
    }
    if(cur->part3==NULL){
        cur->part3 = new Node((cur->x1+cur->x2)/2, (cur->y1+cur->y2)/2, cur->x2, cur->y2);
    }
    if(cur->part4==NULL){
        cur->part4 = new Node(cur->x1, (cur->y1+cur->y2)/2, (cur->x1+cur->x2)/2, cur->y2);
    }
    if(cur->lazy>0){
        cur->part1->lazy = cur->lazy;
        cur->part1->value+=cur->lazy;
        cur->part2->lazy = cur->lazy;
        cur->part2->value+=cur->lazy;
        cur->part3->lazy = cur->lazy;
        cur->part3->value+=cur->lazy;
        cur->part4->lazy = cur->lazy;
        cur->part4->value+=cur->lazy;
        cur->lazy = 0;
    }
    int a = build(cur->part1, x1, y1, x2, y2);
    int b = build(cur->part2, x1, y1, x2, y2);
    int c = build(cur->part3, x1, y1, x2, y2);
    int d = build(cur->part4, x1, y1, x2, y2);
    cur->value = max(max(max(a, b), c), d);
    return cur->value;
}


int main(){
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>X1[i];
    }
    for(int i=0; i<T; i++){
        cin>>Y1[i];
    }
    for(int i=0; i<T; i++){
        cin>>X2[i];
    }
    for(int i=0; i<T; i++){
        cin>>Y2[i];
    }

    int k;
    Node *root = new Node(0, 0, MAXN, MAXN);
    for(int i=0; i<T; i++){
        k = build(root, X1[i], Y1[i], X2[i], Y2[i]);
    }
    cout<<k<<endl;
    cin.get();
}

