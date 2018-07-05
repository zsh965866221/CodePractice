
/**
 * Created by zsh_o on 2018/7/5.
 * 由前序中序构造唯一二叉树
 * 11
 * 0 1 3 4 7 10 2 5 8 6 9
 * 3 1 7 10 4 1 5 8 2 9 6
 * */

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value):val(value),left(NULL),right(NULL){}
};

const int MAXN = 10000;
int Pre[MAXN];
int IndexPre[MAXN];
int In[MAXN];
int IndexIn[MAXN];
int N;

TreeNode* build_tree(int pleft, int pright, int ileft, int iright){
    TreeNode* root = new TreeNode(Pre[pleft]); //前序第一个为根节点
    int r_i = IndexIn[Pre[pleft]]; // 根节点在中序的位置
    int n_left = r_i - ileft;
    int n_right = iright - r_i;
    if(n_left > 0){
        root->left = build_tree(pleft + 1, pleft + n_left, ileft, r_i - 1);
    }else{
        root->left = NULL;
    }
    if(n_right > 0){
        root->right = build_tree(pright - n_right + 1, pright, r_i + 1, iright);
    }else{
        root->right = NULL;
    }

    return root;
}

int main(){
    cin>>N;
    int t;
    for(int i=0; i<N; i++){
        cin>>t;
        Pre[i] = t;
        IndexPre[t] = i;
    }
    for(int i=0; i<N; i++){
        cin>>t;
        In[i] = t;
        IndexIn[t] = i;
    }
    TreeNode* root = build_tree(0, N-1, 0, N-1);

    // 层次遍历输出
    TreeNode* Queue[MAXN];
    int head = 0;
    int tail = 0;
    Queue[tail] = root;
    tail = (tail + 1) % MAXN;
    while(head != tail){
        int cn = (tail - head + MAXN) % MAXN;
        for(int i=0; i<cn; i++){
            TreeNode* t = Queue[head];
            head = (head + 1) % MAXN;
            cout<<t->val<<" ";
            if(t->left != NULL){
                Queue[tail] = t->left;
                tail = (tail + 1) % MAXN;
            }
            if(t->right != NULL){
                Queue[tail] = t->right;
                tail = (tail + 1) % MAXN;
            }
        }
        cout<<endl;
    }
    cin.get();
}