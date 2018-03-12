#include <iostream>
#include <string.h>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
#define maxn 111
using namespace std;
int f[111][111][1300];
int n,m;
int a[maxn];
int a2[maxn];
int a5[maxn];
int main()
{
    int t;
    scanf("%d%d",&n,&m);
    memset(a2,0,sizeof(a2));
    memset(a5,0,sizeof(a5));
    memset(f,-0x3f3f3f3f,sizeof(f));
    f[0][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        while(t%2==0)
        {
            a2[i]++;
            t /= 2;
        }
        while(t%5==0)
        {
            a5[i]++;
            t /= 5;
        }
        for(int j=0;j<=i && j<=m;j++)
            for(int k=0;k<1300;k++)
            {
                f[i][j][k] = max(f[i][j][k],f[i-1][j][k]);
                if(k>=a5[i] && j>0) f[i][j][k] = max(f[i][j][k],f[i-1][j-1][k-a5[i]]+a2[i]);
            }
    }
    int ans = 0;
    for(int i=0;i<1300;i++)
        ans = max(ans,min(f[n][m][i],i));
    printf("%d\n",ans);
    return 0;
}