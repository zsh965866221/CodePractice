
#include <stdio.h>
#include <iostream>
using namespace std;
//
//class A
//{
//public:
//    A(int a)
//    {
//        printf("%d ", a);
//    }
//};
//A a(1);
//int main(void)
//{
//    printf("main ");
//    A c(2);
//    static A b(3);
//    std::cin.get();
//    return 0;
//}

//int main(){
//    char str[][10] = {"China", "Beijing"};
//    char *p = str[0];
//    printf("%s\n", p+1);
//}
void function(int k){
    static int a = k;
    cout<<a<<endl;
}
int main(){
    static int a = 0;
    function(10);
    cout<<a<<endl;
    function(9);
}