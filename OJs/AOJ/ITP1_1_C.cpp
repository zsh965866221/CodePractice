
/**
 * Created by zsh_o on 2018/6/12.
 *
 * 计算矩形的面积和周长
 * */

#include <iostream>
using namespace std;

int main(){
    int high, width;
    cin>>high>>width;
    cout<<high * width<<" "<<2 * (high + width)<<endl;
}