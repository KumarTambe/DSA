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
int main() { 
Node* head = new Node(1);
Node* second = new Node(0);
Node* third = new Node(1);

head->next = second;
second->next = third;
third->next = nullptr;

Node* current = head;
int result = 0;
while(current != nullptr){
    result = result*2+current->val;
    current = current->next;
}
cout << result;
}