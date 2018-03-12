//
// Created by zsh_o on 2018/3/11.
//
/*
 * 末尾连续0的个数，相当于求2和5的因子个数，2*5才会有0出现，每一对2和5都会产生一个0，计算每一个数字的2和5的因子数。例如，40->[3,1]，表示3个2，1个5，25->[0,2]则40*25末尾0的个数为min(3+0, 1+2)=3, 40*25=1000
 *
 * 计算出每一个数字的2和5的因子的个数，
 * 然后暴力搜，会超时。。。
 * 采用先排序，后抽取最大值的方法
 * 四个排序数组，
 * */

#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE = 100;
int N,M;
int factors_2[MAXSIZE];
int factors_5[MAXSIZE];
bool used[MAXSIZE];

int get_factor(int64_t value, int factor){
    int n = 0;
    while(value !=0 && value%factor==0){
        value /= factor;
        n++;
    }
    return n;
}

//Time Limit Error
int search(int m, int f_2, int f_5){
    if(m==M){
        return min(f_2, f_5);
    }
    int c_m = 0;
    for(int i=0; i<N; i++){
        if(!used[i]){
            used[i] = true;
            int t = search(m+1, f_2+factors_2[i], f_5+factors_5[i]);
            used[i] = false;
            c_m = max(t, c_m);
        }
    }
    return c_m;
}

void swap(int L[], int a, int b){
    int t = L[a];
    L[a] = L[b];
    L[b] = t;
}

int resort_2[MAXSIZE];
int resort_5[MAXSIZE];
void m_sort(int factors[], bool (*cmp)(int, int), int indexs[]){
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(cmp(factors[indexs[i]], factors[indexs[j]])){
                swap(indexs, i,j);
            }
        }
    }
}

bool cmp_1(int a, int b){
    return a<b;
}


//Wrong Answer了。。。
int sort_solve(){
    for(int i=0; i<N; i++){
        resort_2[i] = i;
        resort_5[i] = i;
    }
    m_sort(factors_5, cmp_1, resort_2);
    m_sort(factors_2, cmp_1, resort_2);

    m_sort(factors_2, cmp_1, resort_5);
    m_sort(factors_5, cmp_1, resort_5);

    //挑选M/2对
    int i_2 = 0,i_5 = 0;
    int total_2 = 0, total_5 = 0;
    for(int i=0; i<M; i++){
        while(used[resort_2[i_2]]){
            i_2++;
        }
        int total_2_2 = total_2 + factors_2[resort_2[i_2]];
        int total_2_5 = total_5 + factors_5[resort_2[i_2]];
        while(used[resort_5[i_5]]){
            i_5++;
        }
        int total_5_5 = total_5 + factors_5[resort_5[i_5]];
        int total_5_2 = total_2 + factors_2[resort_5[i_5]];

        if(min(total_2_2, total_2_5) > min(total_5_2, total_5_5)){
            used[resort_2[i_2]] = true;
            total_2 = total_2_2;
            total_5 = total_2_5;
        }else{
            used[resort_5[i_5]] = true;
            total_2 = total_5_2;
            total_5 = total_5_5;
        }
    }
    return min(total_2, total_5);
}

int main(){
    cin>>N>>M;
    int64_t a;
    for(int i=0; i<N; i++){
        cin>>a;
        factors_2[i] = get_factor(a, 2);
        factors_5[i] = get_factor(a, 5);
    }
    memset(used, false, MAXSIZE);
//    cout<<search(0, 0, 0)<<endl;
    cout<<sort_solve()<<endl;
    cin.ignore();
    cin.get();
}