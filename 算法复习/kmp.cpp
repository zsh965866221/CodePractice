#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int* get_next(char* A, int s){
    int* next = new int[s];
    next[0] = -1;
    next[1] = 0;
    int i = 2, j = 0;
    while(i < s){
        j = next[i - 1];
        while(j >= 0 && A[i - 1] != A[j]){
            j = next[j];
        }
        next[i] = j + 1;
        i++;
    }
    return next;
}

int kmp_search(char* S, int size_s, char* A, int size_a, int* next){
    int i = 0, j = 0;
    while(i< size_s){
        while(j > 0 && S[i] != A[j]){
            j = next[j];
        }
        i++;
        j++;
        if(j == size_a){
            return i-j;
        }
    }
    return -1;
}

int* get_next_statistic(char* A, int s){
    int* next = new int[s+1];
    next[0] = -1;
    next[1] = 0;
    int i = 2, j = 0;
    while(i <= s){
        j = next[i - 1];
        while(j >= 0 && A[i - 1] != A[j]){
            j = next[j];
        }
        next[i] = j + 1;
        i++;
    }
    return next;
}
int kmp_statistic(char* S, int size_s, char* A, int size_a, int* next){
    int r = 0;
    int i = 0, j = 0;
    while(i < size_s){
        while(j >= 0 && S[i] != A[j]){
            j = next[j];
        }
        j++;
        i++;
        if(j == size_a){
            r++;
            j = next[j];
        }
    }
    return r;
}


int main(){
    char* S = "abababaabcacabaabcacab";
    char* A = "abaabcacab";
    printf("%d\n",kmp_search(S, strlen(S), A, strlen(A), get_next(A, strlen(A))));
    printf("%d\n",kmp_statistic(S, strlen(S), A, strlen(A), get_next_statistic(A, strlen(A))));
}
