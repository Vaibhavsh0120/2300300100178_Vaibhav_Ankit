/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        /*
        [1]->[2]->[3]->[4]
              ^

        [1]->[3]->[3]->[4]

        [1]->[3]------>[4]
        */

        // CASE 1: LAST NODE
        if(node->next == nullptr) {
            node = nullptr;
        }

        // CASE 2: 2ND LAST
        else if(node->next->next == nullptr) {
            node->val = node->next->val;
            node->next = nullptr;
        }

        // CASE 3 MIDDLE LONG
        else {
        node->val = node->next->val;
        node->next = node->next->next;
        }

    }
};