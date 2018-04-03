//
// Created by zsh_o on 2018/4/2.
//

#include <iostream>
using namespace std;

class C1{};
class C2 : public C1{
public:
    C2(){
        int a = 1;
    }
};
class C3:public C2{
public:
    C3(){
        int a = 1;
    }
};
class C4:public virtual C3{
public :
    C4(){
        int a = 1;
    }
};
class C5: public C3, public C2{
public:
    C5(){
        int a = 1;
    }
};
int main(){
    cout<<sizeof(C1)<<" "<<sizeof(C2)<<" "<<sizeof(C3)<<" "<<sizeof(C4)<<" "<<sizeof(C5);
}