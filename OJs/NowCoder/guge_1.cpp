#include <stdio.h>
#include <string.h>

const int MAXT = 100;
const int MAXA = 1e9 + 1;
const int MAXN = 5000 + 1;
const int MAXK = MAXN;

int T;
int N;
int K;
int A[MAXN];
int a;
int main(){
    scanf("%d", &T);
    for(int Case_index=1; Case_index<=T; Case_index++){
        scanf("%d %d", &N, &K);
        memset(A, 0x00, sizeof(A));
        for(int i=0; i<N; i++){
            scanf("%d", &a);
            A[i] = a;
        }
        int day = 0;
        int res = 0;
        bool finished = false;
        while(res <= N){
            for(int i=0; i<K; i++){
                int min_i = -1;
                int min_a = MAXA;
                for(int j=0; j<N; j++){
                    if(A[j] < min_a && A[j] > day){
                        min_i = j;
                        min_a = A[j];
                    }
                }
                //printf("%d %d %d\n", day, min_i, min_a);
                if(min_a != MAXA){
                    res++;
                    A[min_i] = MAXA + 1;
                }else{
                    finished = true;
                    break;
                }
            }
            day++;
            if(finished){
                break;
            }
        }
        printf("Case #%d: %d\n", Case_index, res);
    }
}
