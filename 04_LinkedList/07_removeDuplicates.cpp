
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head;
    while(current != nullptr && current->next != nullptr){
        if(current->val == current->next->val){
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    return head;
}


