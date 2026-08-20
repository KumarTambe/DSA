#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = nullptr;
    }
};

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* L1pointer = l1;
    Node* L2pointer = l2;
    Node* dummy = new Node(0);
    Node* L3pointer = dummy;
    int carry = 0;
    while(L1pointer != nullptr || L2pointer != nullptr || carry != 0){
        int val1 = 0;
        int val2 = 0;
        if(L1pointer != nullptr) val1 = L1pointer->val;
        if(L2pointer != nullptr) val2 = L2pointer->val;
        int sum = val1 + val2 + carry;
        carry = sum/10;
        L3pointer->next = new Node(sum%10);
        L3pointer = L3pointer->next;
        if(L1pointer != nullptr) L1pointer = L1pointer->next;
        if(L2pointer != nullptr) L2pointer = L2pointer->next;
    }
        return dummy->next;
    
}