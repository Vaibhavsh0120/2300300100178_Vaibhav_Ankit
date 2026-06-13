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
    ListNode* removeElements(ListNode* head, int val) {
        
        // dummy node
        ListNode* dummy = new ListNode(-1, head);

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr) {
            // if(curr should be removed)
            if(curr->val == val) {
                curr = curr->next;
                prev->next = curr;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};