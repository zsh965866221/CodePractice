
/**
 * Created by zsh_o on 2018/7/13.
 *
 * 旋转词匹配，判断str2是否是st1的旋转词
 * 方法：拼接两个str1 + str1，在该大串中查看是否存在str2，因为该合并的大串中包含了所有str1的旋转词，故只需要查看str2是否在该大串中即可
 * */

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int str_len(char* S){
    int r = 0;
    while(S[r] != '\0'){
        r++;
    }
    return r;
}

char* str_cat(char* A, int size_a, char* B, int size_b){
    char* r = new char[size_a + size_b];
    memcpy(r, A, size_a * sizeof(A[0]));
    memcpy(r + size_a, B,size_b * sizeof(B[0]));
    r[size_a + size_b] = '\0';
    return r;
}
char* str_cat(char* A, char* B){
    int size_a = strlen(A);
    int size_b = strlen(B);
    char* r = new char[size_a + size_b + 1];
    memcpy(r, A, size_a * sizeof(A[0]));
    memcpy(r + size_a, B,size_b * sizeof(B[0]));
    r[size_a + size_b] = '\0';
    return r;
}

int main(){
    char* A = "abcde";
    char* B = "deabc";
    char* C = str_cat(A, A);
    printf("%s\n", C);

    int size_a = strlen(A);
    int size_b = strlen(B);

    // 获取next数组
    int* next = new int[size_b];
    next[0] = -1;
    next[1] = 0;
    int i = 2, j = 0;
    while(i < size_b){
        j = next[i - 1];
        while(j >= 0 && B[i-1] != B[j]){
            j = next[j];
        }
        next[i] = j + 1;
        i++;
    }

    //根据next数组匹配，B为模板，C为匹配字符串
    int index = -1;
    i = 0, j = 0;
    while(i < size_a * 2){
        while(j>=0 && C[i] != B[j]){
            j = next[j];
        }
        i++;
        j++;
        printf("(%d, %d), ", i, j);
        if(j == size_b){ // 找到模式串
            index = i - j;
            break;
        }
    }

    printf("\n%d", index);
}
