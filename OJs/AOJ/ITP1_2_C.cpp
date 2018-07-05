
/**
 * Created by zsh_o on 2018/7/4.
 * */

#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    cin>>a>>b>>c;
    int mi = min(min(a, b), c);
    int mx = max(max(a, b), c);
    int mc = a + b + c - mi - mx;
    printf("%d %d %d\n", mi, mc, mx);
}