# include <stdio.h>
# include <algorithm>

using namespace std;

bool getResult(int n, int m){
    int ans1 = 0;
    int ans2 = 0;
    while (n > 0){
        int t = min(m, n);
        ans1 += t;
        n -= t;
        int k = n / 10;
        ans2 += k;
        n -= k;
    }
    if (ans1 >= ans2)
        return true;
    else
        return false;
}

int main(){
    int n;
    scanf("%d", &n);
    int low = 1;
    int high = n / 10;
    while (low < high){
        int mid = (low + high) / 2;
        if (getResult(n,mid) == false)
            low = mid + 1;
        else
            high = mid;
    }
    printf("%d", low);
    return 0;
}
