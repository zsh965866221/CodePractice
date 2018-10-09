#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

struct Node{
    long hcode;
    char* key;
    int* value;
    Node* next;
};
typedef Node* LNode;
struct HashMap{
    int HSize;
    LNode* HArray;
};

Node* newNode();
int _strlen(char* s);
bool _stringEQ(char* a, char* b);

Node* HArray;
HashMap* initHashMap(int hsize);
//自定义简易hashcode
long hashcode(char* s);
int* get(char* key, HashMap* hashmap);
void put(char* key, int value, HashMap* hashmap);

// main
int main(){
    HashMap* hashmap = initHashMap(100);
    char S1[] = "abcd";
    char S2[] = "cdab";
    char S3[] = "nnnn";
    put(S1, 10, hashmap);
    put(S2, 20, hashmap);
    int* a = get(S1, hashmap);
    int* b = get(S2, hashmap);
    int* c = get(S3, hashmap);
    printf("%d %d %d\n", *a, *b, c==NULL);
}

int _strlen(char* s){
    int res = 0;
    while(s[res] != '\0'){
        res++;
    }
    return res;
}
bool _stringEQ(char* a, char* b){
    int len1 = _strlen(a);
    int len2 = _strlen(b);
    if(len1 != len2){
        return false;
    }
    for(int i=0; i<len1; i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}
Node* newNode(){
    Node* res = (Node*)malloc(sizeof(Node));
    res->hcode = -1;
    res->key = NULL;
    res->value = (int*)malloc(sizeof(int));
    res->next = NULL;
}

HashMap* initHashMap(int hsize){
    HashMap* hashmap = (HashMap*)malloc(sizeof(HashMap));
    hashmap->HSize = hsize;

    LNode* harray = (LNode*) malloc(sizeof(LNode) * hsize);
    for(int i=0; i<hsize; i++){
        harray[i] = newNode();
    }
    hashmap->HArray = harray;
    return hashmap;
}
long hashcode(char* s){
    long res = 0;
    while(*s != '\0'){
        res += ((int) *s);
        s++;
    }
    return res * res;
}

int* get(char* key, HashMap* hashmap){
    long hcode = hashcode(key);
    int index = hcode % hashmap->HSize;
    Node* hlroot = hashmap->HArray[index];
    Node* p = hlroot->next;
    while(p != NULL){
        if(p->hcode == hcode && _stringEQ(p->key, key)){
            return p->value;
        }
        p = p->next;
    }
    return NULL;
}

void put(char* key, int value, HashMap* hashmap){
    long hcode = hashcode(key);
    int index = hcode % hashmap->HSize;
    Node* hlroot = hashmap->HArray[index];
    Node* p = hlroot->next;
    bool finded = false;
    while(p != NULL){
        if(p->hcode == hcode && _stringEQ(p->key, key)){
            *(p->value) = value;
            finded = true;
            break;
        }
        p = p->next;
    }
    if(finded == false){
        Node* n = newNode();
        n->key = key;
        *(n->value) = value;
        n->hcode = hcode;
        n->next = hlroot->next;
        hlroot->next = n;
    }
}
