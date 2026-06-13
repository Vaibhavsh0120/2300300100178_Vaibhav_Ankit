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
    ListNode* reverseList(ListNode* head) {
        stack<int> stk;
            
        ListNode* temp = head;

        // fill stack
        while(temp != nullptr) {
            stk.push(temp->val);
            temp = temp->next;
        }

        // use stack
        temp = head;
        while(temp != nullptr) {
            temp->val = stk.top();
            stk.pop();
            temp = temp->next;
        }

        return head;
    }
};