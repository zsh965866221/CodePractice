// 两次求相邻区域，第一次求水面区域，标记为确定水面，第二次求陆地区域，过程中所有不是确定水面的全部标记为陆地，最后求陆地面积（在第二次搜索过程中求）
// 需要使用bfs或dfs，都写一遍

#include <stdio.h>
#include <string.h>


const int MAXN = 1e3 + 1;
const int MAXM = 1e3 + 1;
const int MAXSTACK = 1e8 + 1;

int M, N;
int A[MAXM][MAXN];
bool visted[MAXM][MAXN];
//四个方向
int LM[] = {1, -1, 0, 0};
int LN[] = {0, 0, -1, 1};

//把标记为mark，dfs深度优先搜索需要用到栈，judge判断当前遍历点是否符合条件
void dfs(int m, int n, bool (*judge)(int,int), int mark){
    if(!judge(m, n) || visted[m][n]){
        return;
    }
    int* _stack = new int[MAXSTACK];
    int head = 0; // head==0 为空
    _stack[head] = m;
    _stack[head + 1] = n;
    head += 2;
    visted[m][n] = true;
    A[m][n] = mark;

    while(head > 0){
        int cm = _stack[head - 2];
        int cn = _stack[head - 1];
        bool changed = false;
        //判断四个方向
        for(int i=0; i<4; i++){
            int nextm = cm + LM[i];
            int nextn = cn + LN[i];
            if((nextm >=0 && nextm < M) && (nextn >=0 && nextn < N) && !visted[nextm][nextn] && judge(nextm, nextn)){
                _stack[head] = nextm;
                _stack[head + 1] = nextn;
                head += 2;
                visted[nextm][nextn] = true;
                changed = true;
                A[nextm][nextn] = mark;
                //printf("(%d, %d) - ", nextm, nextn);
                break;
            }
        }
        if(!changed){
            head -= 2;
        }
    }
    delete _stack;
}

void _dfs(int m, int n, bool (*judge)(int, int), int mark){
    if(!judge(m, n) || visted[m][n]){
        return;
    }
    visted[m][n] = true;
    A[m][n] = mark;
    for(int i=0; i<4; i++){
        int nextm = m + LM[i];
        int nextn = n + LN[i];
        if(nextm >=0 && nextm < M && nextn >= 0 && nextn < N){
            _dfs(nextm, nextn, judge, mark);
        }
    }
}

void bfs(int m, int n, bool (*judge)(int, int), int mark){
    if(!judge(m, n) || visted[m][n]){
        return;
    }
    // head == tail 为空，不用考虑满的问题
    int* _queue = new int[MAXSTACK];
    int head = 0;
    int tail = 0;
    _queue[head] = m;
    _queue[head + 1] = n;
    head += 2;
    while(head != tail){
        int cm = _queue[tail];
        tail = (tail + 1) % MAXSTACK;
        int cn = _queue[tail];
        tail = (tail + 1) % MAXSTACK;
        visted[cm][cn] = true;
        A[cm][cn] = mark;

        for(int i=0; i<4; i++){
            int nextm = cm + LM[i];
            int nextn = cn + LN[i];
            if(nextm >= 0 && nextm < M && nextn >= 0 && nextn < N && !visted[nextm][nextn] && judge(nextm, nextn)){
                _queue[head] = nextm;
                head = (head + 1) % MAXSTACK;
                _queue[head] = nextn;
                head = (head + 1) % MAXSTACK;
                printf("(%d, %d) - ", nextm, nextn);
            }
        }
    }
    delete _queue;
}

bool judge1(int x, int y){
    return A[x][y] == 0;
}
bool judge2(int x, int y){
    return A[x][y] != -1;
}

int main(){
    memset(visted, 0x00, sizeof(visted));
    scanf("%d%d", &M, &N);
    int a;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &a);
            A[i][j] = a;
        }
    }
    //从上左右均检测一次海域
    for(int i=0; i<N; i++){
        {
            printf("\nstart: (%d, %d) - ", 0, i);
            bfs(0, i, judge1, -1);
        }
    }
    for(int i=0; i<M; i++){
        {
            printf("\nstart: (%d, %d) - ", i, 0);
            bfs(i, 0, judge1, -1);
        }
        {
            printf("\nstart: (%d, %d) - ", i, N-1);
            bfs(i, N-1, judge1, -1);
        }
    }

    for(int i=0; i<N; i++){
        A[M-1][i] = 2;
        printf("\nstart: (%d, %d) - ", M - 1, i);
        bfs(M-1, i, judge2, 2);
    }

    int area = 0;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(A[i][j] == 2){
                area++;
            }
        }
    }
    printf("%d\n", area);
}
