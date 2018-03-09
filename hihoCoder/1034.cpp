//
// Created by zsh96 on 2018/3/8.
//

//看到题想到了两种方法：
//1，对时间t进行模拟；
//2，对m个单位进行模拟
#include <iostream>
#include <vector>

using namespace std;

//struct Node{
//    int64_t t;
//    Node *next;
//    Node(int64_t _t):t(_t),next(NULL){}
//};

struct MagicObj{
    int s;
    int m;
    int r;
//    Node *root;
    int64_t lastTime; //上一次吸收的时间
    MagicObj(int _s,int _m,int _r):s(_s),m(_m),r(_r){
        lastTime = -1;
    }
};

int main(){
    vector<MagicObj*> magicobjs;
    int n;
    cin>>n;
    int m_s, m_m, m_r;
    for(int i=0; i<n; i++){
        cin>>m_s>>m_m>>m_r;
        magicobjs.push_back(new MagicObj(m_s, m_m, m_r));
    }
    int m;
    cin>>m;
    int64_t t;
    int l,r;
    int64_t total = 0;
    for(int i=0; i<m; i++){
        cin>>t>>l>>r;
        for(int j=l-1; j<r; j++){
            MagicObj *magicObj = magicobjs[j];
            int mm;
            if(magicObj->lastTime < 0){
                mm = magicObj->s + t * magicObj->r;
            }else{
                mm = (t - magicObj->lastTime) * magicObj->r;
            }
            int cu = min(magicObj->m, mm);
            total += cu;
            magicObj->lastTime = t;
        }
    }
    cout<<total<<endl;
    cin.ignore();
    cin.get();
}



