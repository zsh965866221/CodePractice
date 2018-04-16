//
// Created by zsh_o on 2018/3/2.
//
#include<iostream>
#include<vector>
#include <cmath>

double tanh(double x){
    return sinh(x)/cosh(x);
}
using namespace std;

void Update(vector<double> &A, vector<vector<double>> &G, double p, double q){
    vector<double> CA(A);
    for(int i=0; i<A.size(); i++){
        double res = p * tanh(CA[i]);
        for(int j=0; j<A.size(); j++){
            res += (q * G[i][j] * tanh(CA[j]));
        }
        A[i] = res;
    }
}

int main() {
    double IA[] = {1,2,3};
    double IG[3][3] = {{1,2,3},{2,1,4},{3,4,1}};
    vector<double> A(IA, IA + 3);
    vector<vector<double>> G;
    G.push_back(vector<double>(IG[0], IG[0]+3));
    G.push_back(vector<double>(IG[1], IG[1]+3));
    G.push_back(vector<double>(IG[2], IG[2]+3));

    Update(A, G, 0.1, 0.2);

    for(int i=0; i<3; i++){
        printf("%.3lf\t",A[i]);
    }
}