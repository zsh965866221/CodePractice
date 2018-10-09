/**
 * ���鼯��ʵ��
*/

#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXN = 1e5 + 1;

/*------------------- ���� -----------------------*/
int Data[MAXN];
int Set[MAXN];
int Depth[MAXN];  // ���Ա����������
// ��ʼ��n��Ԫ�صļ���
void Init(int n){
    for(int i=0; i<n; i++){
        Set[i] = -1;
        Depth[i] = 1;
    }
}
// ����Ԫ��Ԫ��i������һ������
int Find(int i){
    if(Set[i] == -1){
        return i;
    }else{
        return find[Set[i]];
    }
}
// �ǵݹ�
int Find_1(int i){
    while(Set[i]!= -1){
        i = Set[i];
    }
    return i;
}
// �ϲ�����
void Union(int i, int j){
    i = Find(i);
    j = Find(j);
    if(Depth[i] > Depth[j]){
        Set[j] = i;
        Depth[j]++;
    }else{
        Set[i] = j;
        Depth[i]++;
    }
}
// ��·��ѹ����find���ݹ�
int Find_Compress(int i){
    if(Set[i] == -1){
        return i;
    }
    Set[i] = Find_Compress(Set[i]);
    return Set[i];
}
int Find_Compress_1(int i){
    int root = i;
    while(Set[root] != -1){
        root = Set[root];
    }
    int j;
    while(Set[i] != -1){
        j = Set[i];
        Set[i] = root;
        i = j;
    }
    return root;
}


/*------------------- �ṹ�� -----------------------*/
struct Node{
    int value;
    int parent;
    int depth;
    Node():value(0),parent(0),depth(0){}
};
Node List[MAXN];

