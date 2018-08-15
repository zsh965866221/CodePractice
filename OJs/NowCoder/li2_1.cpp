#include <iostream>
#include <stdio.h>
using namespace std;

int dp[105][105] = {0};
void printK(int k, int n, int m)
{
    printf("%d \t %d \t %d \t %d \t %d \n", k, n, m, dp[n][m], dp[n-1][m]);
    if(n == 0)
    {
        for(int i = 0; i < m; i++)
            cout << 'z';
        return;
    }
    else if( m == 0 )
    {
        for(int i = 0; i < n; i++)
            cout << 'a';
        return;
    }

    if(k <= dp[n-1][m])
    {
        cout << 'a';
        printK(k, n - 1, m);
    }
    else
    {
        cout << 'z';
        printK(k - dp[n-1][m], n, m - 1);
    }
}

void PrintDp(int n, int m)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= m; i++)
    {
        dp[0][i] = 1;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
               if(dp[i][j] > 1000000000)
            {
                dp[i][j] = 1000000000;
            }
        }
    }

    printf("--------------------\n");
    PrintDp(n, m);

    if(k > dp[n][m])
    {
        cout << "-1" << endl;
        return 0;
    }

    printK(k, n, m);
    cout << endl;

    return 0;
}
