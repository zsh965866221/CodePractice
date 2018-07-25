/**
 * 有一个字符串数组，返回拼接之后所有字符串字典序最小的字符串
 * 方法：相当于给字符串数组做一次排序过程，比较str1 + str2与str2 + str1的字典序，需要证明
*/

#include <stdio.h>
#include <string.h>

int min(int a, int b){
    return a > b ? b : a;
}

/**
 * 两个字符串的字典序大小
 * 好像字符串结束位'\0'就是最小的字符，故不用管长度的问题了
*/
bool compare_dict_order(char* str1, char* str2){
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int l = min(l1, l2);
    int i = 0;
    while(str1[i] == str2[i]){
        i++;
    }
    return str1[i] < str2[i];
}

char* string_cat(char* str1, char* str2){
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int l = l1 + l2;
    char* r = new char[l1 + l2 + 1];
    int i = 0;
    while(i < l1){
        r[i] = str1[i];
        i++;
    }
    i = l1;
    while(i < l1 + l2){
        r[i] = str2[i - l1];
        i++;
    }
    r[l1 + l2] = '\0';
    return r;
}

int main(){
    char A[][100] = {"ab", "b", "abc", "aba"};
    int size_A = sizeof(A) / sizeof(A[1]);
    char* sp[size_A];
    int i = 0;
    while(i < size_A){
        sp[i] = A[i];
        i++;
    }
    for(i=0; i<size_A-1; i++){
        for(int j=size_A-1; j>i; j--){
            if(!compare_dict_order(string_cat(sp[j-1], sp[j]), string_cat(sp[j], sp[j-1]))){
                char* t = sp[j-1];
                sp[j-1] = sp[j];
                sp[j] = t;
            }
        }
    }

    for(i=0; i<size_A; i++){
        printf("%s\n", sp[i]);
    }

}

