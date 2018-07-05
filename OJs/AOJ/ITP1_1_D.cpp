
/**
 * Created by zsh_o on 2018/6/12.
 *
 * 把一个整数转换成 小时：分钟：秒 的形式
 * */

#include <iostream>
using namespace std;
int main(){
    int S;
    cin>>S;
    int h,m,s;
    s = S % 60;
    m = S / 60;
    h = m / 60;
    m = m - h * 60;
    cout<<h<<":"<<m<<":"<<s<<endl;
}