#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    int k;
    Node* next;
    Node(){
        next = NULL;
    }
};

const int MAXN = 10000 + 1;
Node List[MAXN];
int N[MAXN];

int n;
int k;
int A[1000];
int B[1000];

int main(){
    cin>>n>>k;
    int a;
    memset(N, 0x00, sizeof(N));
    for(int i=1; i<=n; i++){
        Node* node = new Node();
        cin>>a;
        N[a]++;
        node->k = i;
        Node* tnext = List[a].next;
        List[a].next = node;
        node->next = tnext;
    }
    int i = 0;
    int j = MAXN - 1;
    while(N[i] == 0){
        i++;
    }
    while(N[j] == 0){
        j--;
    }
    int ic=0;
    for(ic=0; ic<k; ic++){
        int res = k - ic;
        if(min(N[i], N[j]) > res){
            break;
        }
        N[j]--;
        N[i]--;
        Node* t = List[j].next;
        List[j].next = t->next;
        t->next = List[j-1].next;
        List[j-1].next = t;
        N[j-1]++;
        A[ic] = t->k;

        t = List[i].next;
        List[i].next = t->next;
        t->next = List[i+1].next;
        List[i+1].next = t;
        N[i+1]++;
        B[ic] = t->k;

        if(N[j]==0){
            j--;
        }
        if(N[i]==0){
            i++;
        }
    }

    for(int z=0; z<ic; z++){
        cout<<A[z]<<' '<<B[z]<<endl;
    }

    cout<<j-i<<' '<<ic<<endl;
}
