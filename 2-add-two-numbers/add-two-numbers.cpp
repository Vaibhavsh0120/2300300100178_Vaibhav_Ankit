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
        ListNode* head = new ListNode(0); // no use just to create head;
        ListNode* temp = head;

        int carry = 0;
        while(l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int sum = val1 + val2 + carry; // last carry used in calculating sum
            carry = sum/10; // resets carry and calculate it for next sum

            temp->next = new ListNode(sum%10);
            temp = temp->next;

            if(l1) {
                l1 = l1->next;
            }

            if(l2) {
                l2 = l2->next;
            }
        }

        return head->next; // removed no use starter node with "0"
    }
};