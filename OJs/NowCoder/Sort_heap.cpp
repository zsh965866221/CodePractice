/**
 * 调整[head, end]的堆，head为父节点，使其满足堆的性质
 * 这个需要特别注意的是，这个地方需要满足以head为父节点左右子节点代表的子堆均满足堆序
 * 而且建堆的时候从一个完全无序开始，但调整的时候是从下往上开始的，故当调整完根节点之后所有的堆都调整完成
 * 父节点不满足，当调整父节点和左右子节点这三个节点之后，再调整破坏了的子堆结构即可
 * 这时只需把不满足的父节点每级向下沉即可,沉的过程不破坏当前调整的三个节点的未改变的那个节点的子堆结构
*/

#include <stdio.h>
#include <string.h>

void _swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

void adjMaxHeap(int* A, int left, int right){
    int i = left;
    while(i <= right / 2){
        int lc = (i<<1);
        int rc = (i<<1) + 1;
        int t = 0; //记录当前最大的下标
        if((rc > right) || (A[lc - 1] > A[rc - 1])){
            t = lc;
        }else{
            t = rc;
        }
        if(A[t - 1] > A[i - 1]){
            _swap(A[t-1], A[i - 1]);
            i = t;
        }else{
            return;
        }
    }
}

int* heapSort(int* A, int n){
    // 构建大顶堆
    for(int i=n/2; i>1; i--){
        adjMaxHeap(A, i, n);
    }
    for(int i=n; i>1; i--){
        adjMaxHeap(A, 1, i);
        _swap(A[0], A[i-1]);
    }
    return A;
}

int main(){
    int A[] = {7,4,5,8,2,6,1,4};
    int l = sizeof(A) / sizeof(int);
    heapSort(A, l);
    for(int i=0; i<l; i++){
        printf("%d ", A[i]);
    }
}
