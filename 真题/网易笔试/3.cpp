// 2X - Z < 2a, z为队员总水平，X为第一队，a为第一队最小值
// 2X > Z
#include <stdio.h>
#include <string.h>

const int MAXN = 50;
const int MAXA = 60000+1;
int n;
int A[MAXN];
int a;
int Z;
int X;
int cmin; // 当前第一队最小值
int res = 0;
bool visited[MAXN];

void _search(int i){
    visited[i] = true;
    int t = cmin;
    if(A[i] < cmin){
        cmin = A[i];
    }
    X += A[i];
    if((2*X - Z < 2 * cmin) && (2*X > Z)){
        res++;
    }
    for(int j=i; j<n; j++){
        if(!visited[j]){
            _search(j);
        }
    }
    X -= A[i];
    visited[i] = false;
    cmin = t;

}

int main(){
    scanf("%d", &n);
    Z = 0;
    X = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        A[i] = a;
        Z += a;
    }
    cmin = MAXA;
    memset(visited, 0x00, sizeof(visited));
    for(int i=0; i<n; i++){
        _search(i);
    }
    printf("%d\n", res);
}
