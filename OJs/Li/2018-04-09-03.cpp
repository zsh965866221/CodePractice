//
// Created by zsh_o on 2018/4/9.
//

#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

int main(){
    int K, X, Y;
    cin>>K>>X>>Y;

    ll F[K][9][9]; //F[i][x][y]：走i步落在[x, y]的次数
    memset(F, 0x00, sizeof(F));
    F[0][1][2] = 1;
    F[0][2][1] = 1;
    for(int i=1; i<K; i++){
        for(int x=0; x<=9; x++){
            for(int y=0; y<=9; y++){
                if(x-2>=0 && y-1>=0){
                    F[i][x][y] += F[i-1][x-2][y-1];
                }
                if(x-1>=0 && y-2>=0){
                    F[i][x][y] += F[i-1][x-1][y-2];
                }
                if(x-2>=0 && y+1<=9){
                    F[i][x][y] += F[i-1][x-2][y+1];
                }
                if(x-1>=0 && y+2<=9){
                    F[i][x][y] += F[i-1][x-1][y+2];
                }
                if(x+1<=9 && y+2<=9){
                    F[i][x][y] += F[i-1][x+1][y+2];
                }
                if(x+2<=9 && y+1<=9){
                    F[i][x][y] += F[i-1][x+2][y+1];
                }
                if(x+1<=9 && y-2>=0){
                    F[i][x][y] += F[i-1][x+1][y-2];
                }
                if(x+2<=9 && y-1>=0){
                    F[i][x][y] += F[i-1][x+2][y-1];
                }
            }
        }
    }
    cout<<F[K-1][X][Y]%1000000007<<endl;
    cin.get();
    return 0;
}