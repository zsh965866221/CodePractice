#include <stdio.h>
#include <string.h>

char* fun(){
    char s[] = "abcdefg";
    printf("Fun: %p: %s --- %p \n", s, s, &s);
    return s;
}

char* nfun(){
    char *s = new char[100];
    s = "abcdefg";
    printf("NFun: %p: %s --- %p \n", s, s, &s);
    return s;
}

int main(){
    char* s = fun();
    printf("Main: %p: %s --- %p\n", s, s, &s);
    char* ns = nfun();
    printf("NMain: %p: %s --- %p \n", ns, ns, &ns);
}
