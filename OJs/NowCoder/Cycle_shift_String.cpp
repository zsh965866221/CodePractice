/**
 * 给定一个字符串S和一个位置i，交换[0,i]和[i+1, strlen(S)-1]，相当于循环移位
 * 要求空间复杂度为O(1)时间复杂度为O(n)，也就是不能用声明一个等长数据的方法
 * 这里用的方法为反转字符，和上一个反转句子一样
 *
*/

#include <stdio.h>
#include <string.h>

char* reverse_string(char* S, int size_s){
    char* r = new char[size_s];
    int i = 0;
    while(i < size_s){
        r[i] = size_s - 1 - i;
        i++;
    }
    return r;
}

char* reverse_string_(char* S, int size_s){
    int i = 0;
    while(i < size_s / 2){
        int j = size_s - 1 - i;
        char t = S[i];
        S[i] = S[j];
        S[j] = t;
        i++;
    }
    return S;
}

int main(){
    char S[] = "ABCDEFGH";
    int i = 3;
    int strL = strlen(S);
    int l = i + 1;
    reverse_string_(S, strL);
    reverse_string_(S, strL - l);
    reverse_string_(S + strL - l, l);
    printf("%s\n", S);

}



