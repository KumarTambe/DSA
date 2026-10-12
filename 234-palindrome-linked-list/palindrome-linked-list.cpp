/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
ListNode* slow = head;
    ListNode* fast = head;
    if (head == nullptr || head->next == nullptr) return true;
    while(fast != nullptr && fast->next != nullptr){
        if(fast->next->next == nullptr){
            fast = fast->next;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* prev = nullptr;
    ListNode* current = slow->next;
    while(current != nullptr){
        ListNode* NextNode = current->next;
        current->next = prev;
        prev = current;
        current = NextNode;
    }
    
    ListNode* left = head;
    ListNode* right = prev;
    while(right != nullptr){
        if(left->val != right->val){
            return false;
        }
        left = left->next;
        right = right->next;
    }
    return true;
    }
};