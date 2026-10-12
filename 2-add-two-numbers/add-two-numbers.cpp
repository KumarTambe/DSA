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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* L1pointer = l1;
    ListNode* L2pointer = l2;
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    int carry = 0;
    while(L1pointer != nullptr || L2pointer != nullptr || carry){
        int L1value = L1pointer == nullptr ? 0 : L1pointer->val;
        int L2value = L2pointer == nullptr ? 0 : L2pointer->val;
        int sum = L1value + L2value + carry;
        int digit = sum % 10;
        carry = sum / 10;
        
        ListNode* newNode = new ListNode(digit);
        current->next = newNode;
        current = current->next;
        
        if(L1pointer != nullptr) L1pointer = L1pointer->next;
        if(L2pointer != nullptr) L2pointer = L2pointer->next;
    }
    return dummy->next;
    }
};