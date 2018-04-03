//
// Created by zsh_o on 2018/4/2.
//

#include <iostream>
using namespace std;

class C12{
public:
    C12(int _b){
        b = _b;
    }

    virtual void run(){
        cout<<"C12:"<<b<<endl;
    }
    virtual void run1(){
        cout<<"C12-1"<<endl;
    }
    virtual void run2(){
        cout<<"C12-2"<<endl;
    }

private:
    int b;
};

class C11{
public:
    C11(int _a){
        a = _a;

    }
    virtual void run(){
        cout<<"C11:"<<a<<endl;
    }
    virtual void run1(){
        cout<<"C11-1"<<endl;
    }

private:
    int a;
};
class C2:C11,C12{
public:
    C2(int _a, int _b, int _ca) : C12(_b), C11(_a) {
        ca = _ca;
    }

    virtual void run(){
        cout<<"C2:"<<ca<<endl;
    }
private:
    int ca;
};
int main(){
    C11* c11 = new C11(1);
    c11->run();
    c11->run1();
    C12 *c12 = (C12*)c11;
    c12->run();
    c11->run1();
    C2 *tc2 = (C2 *)c11;
    tc2->run();
    c11 = (C11*) new C2(1, 2, 3);
    c11->run();
    c11->run1();
    c12  = (C12*)c11;
    c12->run();
    c12->run2();
//    c2 = (C2*)c1;
//    c2->run();


//    //----------
//    C12* c12 = new C12(1);
//    c12->run();
//    C11 *c11 = (C11*)c12;
//    c11->run();
//    C2 *tc2 = (C2 *)c12;
//    tc2->run();
//    //----------
    cin.get();
}