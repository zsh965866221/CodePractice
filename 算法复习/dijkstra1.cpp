
/*
6 8
0 5 100
0 4 30
0 2 10
1 2 5
2 3 50
3 5 10
4 3 20
4 5 60
*/

#include <stdio.h>
#include <string.h>

const int MAXN = 100;
const int MAXV = 1e9 + 1;

int _min(int a, int b){
    return a > b ? b : a;
}
int G[MAXN][MAXN];
int N, M;
// 从start节点开始
// 图为G，邻接矩阵表示，节点个数为n
int* dijkstra(int start);

int main(){
    scanf("%d %d", &N,&M);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            G[i][j] = MAXV;
        }
    }
    int a, b, c;
    for(int i=0; i<M; i++){
        scanf("%d %d %d", &a, &b, &c);
        G[a][b] = c;
    }

    int* Lmin = dijkstra(1);
    for(int i=0; i<N; i++){
        printf("%d ", Lmin[i]);
    }
}

int* dijkstra(int start){
    int* Lmin = new int[N];
    for(int i=0; i<N; i++){
        Lmin[i] = MAXV;
    }
    Lmin[start] = 0;
    bool* visited = new bool[N];
    memset(visited, 0x00, sizeof(bool) * N);
    int c_node = start;
    for(int i=0; i<N; i++){
        visited[c_node] = true;
        // 根据c_node更新没有访问过的Lmin的值
        for(int j=0; j<N; j++){
            if(visited[j] == false && G[c_node][j] < MAXV){
                Lmin[j] = _min(Lmin[j], Lmin[c_node] + G[c_node][j]);
            }
        }
        //根据没有访问过的Lmin的最小值确定c_node
        int mmin = MAXV;
        for(int j=0; j<N; j++){
            if(visited[j] == false && Lmin[j] < mmin){
                mmin = Lmin[j];
                c_node = j;
            }
        }
    }
    return Lmin;
}
