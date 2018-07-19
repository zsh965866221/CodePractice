/**
 * ����һ���ַ���S��һ��λ��i������[0,i]��[i+1, strlen(S)-1]���൱��ѭ����λ
 * Ҫ��ռ临�Ӷ�ΪO(1)ʱ�临�Ӷ�ΪO(n)��Ҳ���ǲ���������һ���ȳ����ݵķ���
 * �����õķ���Ϊ��ת�ַ�������һ����ת����һ��
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



