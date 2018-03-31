//
// Created by zsh_o on 2018/3/30.
//

/**
 * 二叉搜索树
 *
 * 报超时，不知道为啥
 * */

#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE = 10000+1;
int parents[MAXSIZE];
int leftChildren[MAXSIZE];
int rightChildren[MAXSIZE];

int heap[2*MAXSIZE];
int hp;
int theap[2*MAXSIZE];
int thp;

void preOrder(int root){
    hp = 0;
    heap[hp] = root;
    int p;
    while(hp>-1){
        p = heap[hp];
        hp--;
        cout<<p<<" ";

        if(rightChildren[p]!=-1){
            hp++;
            heap[hp] = rightChildren[p];
        }
        if(leftChildren[p]!=-1){
            hp++;
            heap[hp] = leftChildren[p];
        }
    }
}

void preOrder_1(int root){
    int p = root;
    hp = -1;
    while(p!=-1 ||hp>-1){
        while(p!=-1){
            cout<<p<<" ";
            hp++;
            heap[hp] = p;
            p = leftChildren[p];
        }
        p = heap[hp];
        hp--;
        p = rightChildren[p];
    }
}

void inOrder(int root){
    int p = root;
    hp = -1;
    while(p!=-1 || hp>-1){
        while(p!=-1){
            hp++;
            heap[hp] = p;
            p = leftChildren[p];
        }
        p = heap[hp];
        cout<<p<<" ";
        hp--;
        p = rightChildren[p];
    }
}

void postOrder(int root){
    int p = root;
    int pre = -1;
    hp = -1;
    while(p!=-1 || hp>-1){
        while(p!=-1){
            hp++;
            heap[hp] = p;
            p = leftChildren[p];
        }
        p = heap[hp];
        if(rightChildren[p]!=-1 && rightChildren[p]!=pre){
            p = rightChildren[p];
        }else{
            hp--;
            cout<<p<<" ";
            pre = p;
            p = -1;
        }
    }
}

void postOrder_1(int root){
    int pre = -10;
    hp = 0;
    heap[hp] = root;
    int p;
    while(hp>-1){
        p = heap[hp];
        if(p < 0){
            cout<<"()";
            pre = p;
            hp--;
            continue;
        }
        if((rightChildren[p]>0? rightChildren[p]:-2) == pre){
            hp--;
//            cout<<p<<" "; //后序
            cout<<")";
            pre = p;
            continue;
        }
        if(p>0){
            cout<<"("<<p; //先序
        }
        hp++;
        heap[hp] = rightChildren[p]>0? rightChildren[p]:-2;
        hp++;
        heap[hp] = leftChildren[p]>0? leftChildren[p]:-1;
    }
}

void recursion(int root){
    if(root==-1){
        cout<<"()";
        return;
    }
    cout<<"("<<root;
    recursion(leftChildren[root]);
    recursion(rightChildren[root]);
    cout<<")";
}


int main(){
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        memset(parents, 0xff, sizeof(parents));
        memset(leftChildren, 0xff, sizeof(leftChildren));
        memset(rightChildren, 0xff, sizeof(rightChildren));
        int N;
        int a,b;
        cin>>N;
        int error = 10;
        for(int j=0; j<N-1; j++){
            scanf("%d %d", &a, &b);
            if(parents[b] != -1){
                error = min(error, 1);
            }
            parents[b] = a;

            if(leftChildren[a]!=-1 && rightChildren[a]!=-1){
                error = min(error, 2);
            }else {
                if(a>b){
                    if(leftChildren[a]!=-1){
                        error = min(error, 3);
                    }else{
                        leftChildren[a] = b;
                    }
                }else{
                    if(rightChildren[a]!=-1){
                        error = min(error, 3);
                    }else{
                        rightChildren[a] = b;
                    }
                }
            }
        }
        if(error<10){
            cout<<"ERROR"<<error<<endl;
            continue;
        }
        int p = 1;
        while(parents[p]!=-1){
            p = parents[p];
        }

        postOrder_1(p);

    }

    cin.get();
}