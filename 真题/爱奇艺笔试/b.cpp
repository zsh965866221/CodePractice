#include <stdio.h>
#include <string.h>

const int MAXN = 100 + 1;
const int MAXM = 100 + 1;
const int MAXP = 100 + 1;
const int MAXA = 1000 + 1;

int N, M, P, a;
int A[MAXN];
int main(){
    scanf("%d%d%d", &N, &M, &P);
    for(int i=0; i<N; i++){
        scanf("%d", &a);
        A[i] = a;
    }
    for(int t=0; t<M; t++){
        scanf("%c", &tag);
        scanf("%d", &t_v);
        if(tag == 'A'){
            A[t_v-1] ++;
        }else if (tag == 'B'){
            A[t_v-1] --;
        }
    }
    int value = A[P-1];
    int rank = 1;
    for(int i=0; i<N; i++){
        if(A[i] > value){
            rank ++;
        }
    }
    printf("%d\n", rank);
}
