class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // ready to delete head node if duplicate
        ListNode* dummy = new ListNode(0, head);

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            // if duplicate value found
            if (curr->next && curr->val == curr->next->val) {
                int val = curr->val;

                // keep skipping till null or different value
                while (curr && curr->val == val) {
                    curr = curr->next;
                }

                // connect
                prev->next = curr;
            }
            // if not duplicate, keep moving forward 
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};