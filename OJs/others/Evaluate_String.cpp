//
// Created by zsh96 on 2018/4/20.
//
/**
 * 计算字符串的值，后缀表达式
 * */

#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <stack>

using namespace std;

struct Item{
    bool isNumber;
    char symbol;
    double value;
    Item(double value):isNumber(true),value(value){}
    Item(char symbol):isNumber(false),symbol(symbol){}
};

class Operator{
public:
    char label;
    explicit Operator(char label): label(label){}
    virtual double calculate(double a, double b)=0;
};
class Add:public Operator{
public:
    Add() : Operator('+') {}
    double calculate(double a, double b) override {
        return a + b;
    }
};
class Sub:public Operator{
public:
    Sub() : Operator('-') {}
    double calculate(double a, double b) override {
        return a - b;
    }
};
class Mul:public Operator{
public:
    Mul() : Operator('*') {}
    double calculate(double a, double b) override {
        return a * b;
    }
};
class Div:public Operator{
public:
    Div() : Operator('/') {}
    double calculate(double a, double b) override {
        return a / b;
    }
};

class OperatorManager{
public:
    map<char, Operator *> operatorList;
    map<char, int> operatorLevel;
    OperatorManager(){
        operatorList['+'] = new Add();
        operatorList['-'] = new Sub();
        operatorList['*'] = new Mul();
        operatorList['/'] = new Div();

        operatorLevel['+'] = 1;
        operatorLevel['-'] = 1;
        operatorLevel['*'] = 2;
        operatorLevel['/'] = 2;
        operatorLevel['('] = 3;
        operatorLevel[')'] = 3;
    }
    double calculate(char operc, double a, double b){
        return operatorList[operc]->calculate(a, b);
    }
};

bool isNumber(char c){
    return c>='0' && c<='9';
}
double e10(int n){
    double res = 10;
    while(--n){
        res *= 10;
    }
    return res;
}
OperatorManager operatorManager;
int main(){
    cout<<"Inputs: ";
    string line;
    getline(cin, line);

    vector<Item *> Items;
    double sum = 0;
    bool isfloat = false;
    bool isnegative = false;
    char LastC = '~';
    int floatNum = 0;
    bool lastisNumber = (line[0]!='(');
    for(int i=0; i<line.size(); i++){
        char c = line[i];
        if(!isNumber(c)){
            if(c == '-' && (LastC == '(' || LastC == '~')){
                Items.push_back(new Item(0.));
            }
            if(c=='.'){
                if(isfloat){
                    cout<<"Error"<<endl;
                }else{
                    isfloat = true;
                }
                lastisNumber = true;
            }else{
                if(c == ' '){
                    continue;
                }
                if(lastisNumber){
                    Items.push_back(new Item(sum));
                }
                Items.push_back(new Item(c));
                sum = 0;
                floatNum = 0;
                isfloat = false;
                lastisNumber = false;
                LastC = c;
            }
        }else {
            double t = c - '0';
            if (!isfloat) {
                sum = sum * 10 + t;
            } else {
                floatNum++;
                sum = sum + (c - '0') / e10(floatNum);
            }
            lastisNumber = true;
            if (i == line.size() - 1) {
                Items.push_back(new Item(sum));
            }
            LastC = c;
        }
    }

    // 转为后缀表达式
    vector<Item *> postfix;
    stack<Item *> temp_stack;

    for(int i=0; i<Items.size(); i++){
        Item *item = Items[i];
        if(item->isNumber){
            postfix.push_back(item);
        }else{
            if(item->symbol=='('){
                temp_stack.push(item);
            }else if(item->symbol==')'){
                Item *temp = temp_stack.top();
                while(!temp_stack.empty() && temp->symbol!='('){
                    postfix.push_back(temp);
                    temp_stack.pop();
                    if(!temp_stack.empty())
                        temp = temp_stack.top();
                }
                temp_stack.pop();
            }else{
                if(!temp_stack.empty()){
                    Item *temp = temp_stack.top();
                    while(!temp_stack.empty() && operatorManager.operatorLevel[temp->symbol]>=operatorManager.operatorLevel[item->symbol] && temp->symbol!='('){
                        postfix.push_back(temp);
                        temp_stack.pop();
                        if(!temp_stack.empty())
                            temp = temp_stack.top();
                    }
                }
                temp_stack.push(item);
            }
        }
    }
    while(!temp_stack.empty()){
        postfix.push_back(temp_stack.top());
        temp_stack.pop();
    }

    // ------
    cout<<"Items: ";
    for(int i=0; i<Items.size(); i++){
        Item *item = Items[i];
        if(item->isNumber){
            cout<<item->value;
        }else{
            cout<<item->symbol;
        }
    }
    cout<<endl;
    cout<<"Postfix Expression: ";
    for(int i=0; i<postfix.size(); i++){
        Item *item = postfix[i];
        if(item->isNumber){
            cout<<item->value;
        }else{
            cout<<item->symbol;
        }
    }
    cout<<endl;

    // 计算
    for(int i=0; i<postfix.size(); i++){
        Item *item = postfix[i];
        if(item->isNumber){
            temp_stack.push(item);
        }else{
            Item *b = temp_stack.top();
            temp_stack.pop();
            Item *a = temp_stack.top();
            temp_stack.pop();
            temp_stack.push(new Item(operatorManager.calculate(item->symbol, a->value, b->value)));
        }
    }
    // -----
    Item *result = temp_stack.top();
    printf("Result: %.3lf\n", result->value);
    cin.get();
}