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

Node* removeNthFromEnd(Node* head, int n) {
    Node* slow = head;
    Node* fast = head;
    for(int i =0; i<n; i++){
        fast = fast->next;
    }
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}
