#include <stdio.h>
#include <string.h>

int main(){
    int a = 1;
    int b = a++;
    printf("%d %d %d %d %d", a, a++, a, ++a, a);
}
