#include <stdio.h>
#include <string.h>

void _swap(char& a, char& b){
    char t = a;
    a = b;
    b = t;
}

void _inv(char* S, int left, int right){
    int n = right - left + 1;
    int i = 0;
    while(i < n / 2){
        _swap(S[left + i], S[right - i]);
        i++;
    }
}

char S[10000];
int k;
int N;
int main(){
    scanf("%s", S);
    scanf("%d", &k);
    N = strlen(S);
    int i = 0;
    while(i + 3 * k - 1 < N){
        _inv(S, i, i + k - 1);
        i = i + 3 * k;
    }
    printf("%d\n", i);
    int res = N - i;
    if(res < k){
        _inv(S, i, N-1);
    }else{
        _inv(S, i, i + k - 1);
    }
    printf("%s\n", S);
}
