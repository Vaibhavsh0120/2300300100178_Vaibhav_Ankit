/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(0), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        int size = 1;
        ListNode* curr = head;

        // Find the tail and the size
        while(curr->next) {
            size++;
            curr = curr->next;
        }

        k %= size;

        if(k == 0) {
            return head;
        }

        // Make the list circular
        curr->next = head;

        // Move to the new tail
        int steps = size - k - 1;
        curr = head;

        while(steps--) {
            curr = curr->next;
        }

        // New head
        head = curr->next;

        // Break the circle
        curr->next = nullptr;

        return head;
    }
};