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
    Node* fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    Node* current = head;
    while(current != nullptr){
        cout << current->val << " ";
        current = current-> next;
    }
}