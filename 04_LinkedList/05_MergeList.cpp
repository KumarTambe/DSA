#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x){ val = x; next = nullptr; }
};

Node* mergeTwoLists(Node* list1, Node* list2){
    Node* dummy = new Node(0);
    Node* current = dummy;
    
    while(list1 != nullptr && list2 != nullptr){
        // your comparison and attachment logic here
        if(list1->val < list2->val || list1->val == list2->val){
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    if(list1 != nullptr) current->next = list1;
if(list2 != nullptr) current->next = list2;
    
    return dummy->next;
}

int main(){
    // list1: 1→2→4
    Node* List1a = new Node(1);
    Node* List1b = new Node(2);
    Node* List1c = new Node(4);
    List1a->next = List1b;
    List1b->next = List1c;

    // list2: 1→3→4
    Node* List2a = new Node(1);
    Node* List2b = new Node(3);
    Node* List2c = new Node(4);
    List2a->next = List2b;
    List2b->next = List2c;

    Node* result = mergeTwoLists(List1a, List2a);
    while(result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }
}