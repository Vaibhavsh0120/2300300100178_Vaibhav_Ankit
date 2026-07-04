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
        /*
        1. - convert to array then solve
        2. - Use stack to save value and traverse again
        3. - 3 ptr prev, curr, next only 1 traversal
        */

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while(curr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
           
        }

        return  prev;
    }
};