//
// Created by zsh96 on 2018/4/16.
//
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    void recusive(ListNode *head, vector<int> &result){
        if(head!=NULL){
            if(head->next!=NULL){
                recusive(head->next, result);
            }
            result.push_back(head->val);
        }
    }

    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        recusive(head, result);
        return result;
    }
};

class Solution_1 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;

        ListNode *root, *next, *pre;
        root = head;
        next = pre = NULL;
        while(root!=NULL){
            next = root->next;
            root->next = pre;
            pre = root;
            root = next;
        }
        root = pre;

        while(root!=NULL){
            result.push_back(root->val);
            root = root->next;
        }

        return result;
    }
};