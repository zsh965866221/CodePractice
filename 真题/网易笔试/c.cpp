#include <iostream>
using namespace std;
int m=0;
long long n;
int main(){
    cin>>n;
    if(n<=20)
        m=1;
    else
        m = 5-100/n;
    cout<<m<<endl;
}
