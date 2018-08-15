#include <stdio.h>

int _max(int a, int b){
    return a > b ? a : b;
}

int a, b, c;
int main(){
    scanf("%d %d %d", &a, &b, &c);
    int s1 = a + b + c;
    int s2 = a * b * c;
    int s3 = a + b * c;
    int s4 = a * b + c;
    int s5 = (a + b) * c;
    int s6 = a * (b + c);
    int res = _max(s1, _max(s2, _max(s3, _max(s4, _max(s5, s6)))));
    printf("%d", res);
}
