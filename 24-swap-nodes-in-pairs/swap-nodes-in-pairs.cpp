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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr && curr->next) {
            // set next variables
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;

            // Reverse Link
            curr->next = nextPair;
            second->next = curr;
            prev->next = second;

            // move ahead
            prev = curr;
            curr = nextPair;
        }

        return dummy->next;
    }
};