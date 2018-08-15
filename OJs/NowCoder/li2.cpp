#include <stdio.h>

const int MAXN = 100 * 2;
int n, m, k;
char A[MAXN];

void _swap(char& a, char& b){
    char t = a;
    a = b;
    b = t;
}
void _reverse(char* A, int a, int b){
    int i = 0;
    while(i < (b - a + 1)/2){
        _swap(A[a+i], A[b-i]);
        i++;
    }
}
void _printList(char* A, int n){
    for(int i=0; i<n; i++){
        printf("%c", A[i]);
    }
    printf("\n");
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<n; i++){
        A[i] = 'a';
    }
    for(int i=n; i<m+n; i++){
        A[i] = 'z';
    }
    printf("%d    ", 1);
    _printList(A, m+n);
    int i = n - 1;
    bool finded = false;
    int index = 0;
    while(index < k-1){
        if(i+1 < m+n){
            _swap(A[i], A[i+1]);
            index++;
            i++;
        }else{
            int p = i - 1;
            while(A[p]=='a'){
                p--;
            }
            while(A[p]=='z'){
                p--;
            }
            if(p<0){
                printf("False\n");
                break;
            }else{
                _swap(A[p], A[p+1]);
                _reverse(A, p+2, n+m-1);
                index++;
                i = p + 2;
                while(A[i]=='a')
                    i++;
                i--;
            }
        }
        printf("%d    ", index+1);
        _printList(A, m+n);
    }
}

