/**
 * ��һ���ַ������飬����ƴ��֮�������ַ����ֵ�����С���ַ���
 * �������൱�ڸ��ַ���������һ��������̣��Ƚ�str1 + str2��str2 + str1���ֵ�����Ҫ֤��
*/

#include <stdio.h>
#include <string.h>

int min(int a, int b){
    return a > b ? b : a;
}

/**
 * �����ַ������ֵ����С
 * �����ַ�������λ'\0'������С���ַ����ʲ��ùܳ��ȵ�������
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

