//
// Created by zsh96 on 2018/4/20.
//

// 思路，统计出所有gcd的个数

#include <iostream>
using namespace std;

const int MAXN = 100000+1;

int N;
int n, m, p;

int A[MAXN];

int gcd(int m, int n)
{
    while(m>0)
    {
        int c = n % m;
        n = m;
        m = c;
    }
    return n;
}
int main(){
    cin>>N>>n>>m>>p;
    A[0] = 0;
    A[1] = p;
    for(int i=2; i<=N; i++){
        A[i] = (A[i-1]+153)%p;
    }
    int sum = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            sum += (A[gcd(i, j)]);
        }
    }
    cout<<sum<<endl;
    cin.get();
}