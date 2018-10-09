// n1, n2 要求 n1>= n2
#include <iostream>
using namespace std;
typedef long long ll;
ll n;

// 妞妞每次取m个最终的比分，但要求n1>=n2
bool _get(ll n, ll m);
ll _min(ll a, ll b);
int main(){
    cin>>n;
    ll low = 1;
    ll high = n;
    ll mid;
    while (low < high){
        mid = (high + low) / 2;
        if (_get(n, mid) == false){
            printf("%lld, %lld - %lld - false\n", low, high, mid);
            low = mid + 1;
        }else{
            printf("%lld, %lld - %lld - true\n", low, high, mid);
            high = mid;
        }
    }
    printf("%lld\n", low);
}

ll _min(ll a, ll b){
    return a > b ? b : a;
}

bool _get (ll n, ll m){
    ll n1 = 0;
    ll n2 = 0;
    ll res = n;
    ll t;
    while (res > 0){
        t = _min(res, m);
        n1 += t;
        res -= t;
        t = res / 10;
        n2 += t;
        res -= t;
    }
    if (n1 >= n2){
        return true;
    }else {
        return false;
    }
}
