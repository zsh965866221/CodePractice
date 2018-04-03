//
// Created by zsh_o on 2018/4/2.
//

#include <iostream>
using namespace std;

class C1{
public:
    C1(int _a){
        a = _a;

    }
    virtual void run(){
        cout<<"1:"<<a<<endl;
    }

private:
    int a;
};
class C2:C1{
public:
    C2(int _b, int _a) : C1(_a) {
        a = _a;
    }

    virtual void run(){
        cout<<"2:"<<a<<endl;
    }
private:
    int a;
};
int main(){
    C1* c1 = new C1(1);
    c1->run();
    C2 *c2 = (C2*)c1;
    c2->run();
    delete c1;
    c1 = (C1*) new C2(0, 2);
    c1->run();
    c2 = (C2*)c1;
    c2->run();
}