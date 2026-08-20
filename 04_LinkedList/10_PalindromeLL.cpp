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
Node* reverse(Node*head){
    Node* prev = nullptr;
    Node* current = head;
    while(current!= nullptr){
        Node* Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
    }
    return prev;
}

bool palindromeLL(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* secondHalf = reverse(slow->next);
    Node* firstHalf = head;
    while(secondHalf != nullptr){
        if(firstHalf->val != secondHalf->val){
            return false;
        } else{
            secondHalf = secondHalf->next;
            firstHalf = firstHalf->next;
        }
    }
    return true;
}


