/*
 * 对一个句子进行反转，每个词不反转
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
 * 对一个字符串逆序
*/
char* reverse_string(char* s, int size_s){
    char* r = new char[size_s];
    int i = 0;
    while(i < size_s){
        int j = size_s - 1 - i;
        r[i] = s[j];
        i++;
    }
    return r;
}
char* reverse_string_(char* s, int size_s){
    int i = 0;
    while(i < size_s/2){
        char a = s[i];
        int j = size_s - 1 - i;
        s[i] = s[j];
        s[j] = a;
        i++;
    }
    return s;
}

int main(){
    char* s = "abcdefg";
    printf("%s\n", reverse_string(s, strlen(s)));
//    printf("%s\n", reverse_string_(s, strlen(s))); // s定义在栈区无法赋值

    char a[] = "abcdefg";
    printf("%s\n", reverse_string(s, strlen(s)));
    printf("%s\n", reverse_string_(a, strlen(a)));

    char t[] = "abc def ghi"; //反转句子，单词不反转
    reverse_string_(t, strlen(t));
    printf("%s\n", t);
    int i = 0, j = 0;
    while(i <= strlen(t)){
        if(t[i] == ' ' || t[i] == '\0'){
            reverse_string_(t+j, i-j);
            j = i + 1;
        }
        i++;
    }
    printf("%s\n", t);

}
