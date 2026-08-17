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

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    
    head->next = second;
    second->next = third;
    third->next = nullptr;

    Node* prev = nullptr;
    Node* current = head;
    while(current != nullptr){
        Node* Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
    }
    
    while(prev != nullptr){
        cout << prev->val << " ";
        prev = prev->next;
    }
}

