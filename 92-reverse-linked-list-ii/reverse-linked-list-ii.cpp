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
    public:
    void reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // return prev;
        return;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* dummy = new ListNode(0, head);

        ListNode* preLeftPtr = dummy;
        ListNode* leftPtr = nullptr;
        ListNode* rightPtr = nullptr;
        ListNode* postRightPtr = nullptr;

        ListNode* curr = dummy;

        int pos = 0;

        // find preLeftPtr, leftPtr and rightPtr, postRightPtr
        while(curr) {
            // 1  before left found
            if (pos == left - 1) {
                preLeftPtr = curr;
                leftPtr = curr->next;
            }

            // right found
            if (pos == right) {
                rightPtr = curr;
                postRightPtr = curr->next;
                break;
            }

            curr = curr->next;
            pos++;
        }

        // break link
        rightPtr->next = nullptr;

        // reverse
        reverse(leftPtr);

        // link back
        preLeftPtr->next = rightPtr;
        leftPtr->next = postRightPtr;

        return dummy->next;
    }
};