//
// Created by zsh_o on 2018/3/26.
//

#include <map>
#include <cmath>
#include <queue>
#include <ctime>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

queue<int> q;
long long f[2000000];
int n, m, p, N, a[50];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool v[2000000];
char ch[100];

void work() {
    scanf("%d%d", &n, &m);
    p = n*m;
    for (int i = 0; i <n; ++i){
        scanf("%s", ch);
        for (int j = 0; j <m; ++j){
            a[i*m+j] = ch[j] == '1';
        }
    }
    int s = 0;
    for (int i = p - 1; i >= 0; --i) {
        s <<= 1;
        s += a[i];
    }
    N = 1 << p;

    q.push(s);
    f[s] = 1;
    v[s] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < p; ++i) {
            if (((now >> i) & 1) == 0) {
                int x = i/m, y = i%m;
                for (int j = 0; j < 4; ++j) {
                    int xx = x + dx[j], yy = y + dy[j];
                    int idx = xx*m + yy;
                    if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
                        continue;
                    }
                    if ((now >> idx) & 1) {
                        f[now|(1<<i)] += f[now];
                        if (!v[now|(1<<i)]) {
                            q.push(now|(1<<i));
                            v[now|(1<<i)] = true;
                        }
                        break;
                    }
                }
            }
        }
    }
    printf("%lld\n", f[N-1]);
}


int main() {
    work();
}
