#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool *visited = new bool[rows*cols];
        memset(visited,0,rows*cols);
        int count;
        count=movingCountCore(threshold,rows,cols,0,0,visited);

        delete[] visited;
        return count;
    }
    int movingCountCore(int threshold,int rows,int cols,int row,int col, bool* visited){
        int count=0;
        if(row>=0&&row<rows&&col>=0&&col<cols&&!visited[row*cols+col]&&getSum(row)+getSum(col)<=threshold){
            count++;
            visited[row * cols + col] = true;
            count=count+movingCountCore(threshold,rows,cols,row-1,col,visited)
                  +movingCountCore(threshold,rows,cols,row+1,col,visited)
                  +movingCountCore(threshold,rows,cols,row,col-1,visited)
                  +movingCountCore(threshold,rows,cols,row,col+1,visited);
        }
        return count;
    }
    int getSum(int num){
        int sum=0;
        while (num>0){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
};

class Solution_dp {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<0){
            return 0;
        }
        if(threshold==0){
            return 1;
        }
        int MAXINTER = 1000;
        bool F[MAXINTER*rows*cols];
        bool Enterable[rows*cols];
        memset(F, 0x00, sizeof(F));
        memset(Enterable, 0x00, sizeof(Enterable));
        int count = 1;
        F[0] = true;
        for(int x=0; x<rows; x++){
            for(int y=0; y<cols; y++){
                Enterable[x*cols + y] = (getSum(x) + getSum(y) <= threshold);
            }
        }
        for(int i=1; i< MAXINTER; i++){
            int cc = 0;
            for(int x=0; x<rows; x++){
                for(int y=0; y<cols; y++){
                    // index = i*cols*rows + cols*x + y
                    if(!Enterable[x*cols + y]){
                        continue;
                    }
                    if(F[(i - 1) * cols * rows + cols * x + y]){
                        F[i*cols*rows + cols*x +y] = true;
                        continue;
                    }else{
                        if((x-1<0? false:F[(i-1)*cols*rows + cols*(x-1) +y]) ||
                                (x+1>=rows? false:F[(i-1)*cols*rows + cols*(x+1) + y]) ||
                                (y-1<0? false:F[(i-1)*cols*rows + cols*x + (y-1)]) ||
                                (y+1>=cols? false:F[(i-1)*cols*rows + cols*x + (y+1)])){
                            count++;
                            F[i*cols*rows + cols*x +y] = true;
                            cc++;
                        }
                    }
                }
            }
            if(cc==0){
                break;
            }
        }
        return count;
    }
    int getSum(int num){
        int sum=0;
        while (num>0){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
};

int main(){
    Solution solution;
    Solution_dp solution_dp;
    cout<<solution.movingCount(30, 10, 20)<<endl;
    cout<<solution_dp.movingCount(30, 10, 20)<<endl;
    cin.get();
}