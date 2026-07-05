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
    void reorderList(ListNode* head) {
        /*
        1. Find the middle and split.
        2. Reverse the second half.
        3. Merge alternately.
        */
        if (head == nullptr || head->next == nullptr) {
            return;
        }
    
        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
    
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
    
        // Split into two halves
        prev->next = nullptr;
    
        // Reverse second half
        ListNode* second = nullptr;
        ListNode* curr = slow;
    
        while(curr) {
            ListNode* next = curr->next;
            curr->next = second;
            second = curr;
            curr = next;
        }
    
        // Merge alternately
        ListNode* first = head;
    
        while(first && second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
    
            first->next = second;
    
            if (t1 == nullptr)
                break;
    
            second->next = t1;
    
            first = t1;
            second = t2;
        }
    }
};