#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char* s1 = "abcdefg";
    char* s2 = "abcdefg";
    char a1[] = "abcdefg";
    char a2[] = "abcdefg";
    const char ca1[] = "abcdefg";
    const char ca2[] = "abcdefg";
    const char* cs1 = "abcdefg";
    const char* cs2 = "abcdefg";
    printf("%d %d %d %d %d", s1==s2, a1==a2, ca1==ca2, cs1==cs2, s1==cs1);
}
