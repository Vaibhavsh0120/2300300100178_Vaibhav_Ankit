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
    void mergeAlternate(ListNode* one, ListNode* two) {

        ListNode* onePtr = one;
        ListNode* twoPtr = two;

        while (onePtr && twoPtr) {
            ListNode* oneNext = onePtr->next;
            ListNode* twoNext = twoPtr->next;

            onePtr->next = twoPtr;
            twoPtr->next = oneNext;

            onePtr = oneNext;
            twoPtr = twoNext;
        }

        return;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while(curr) {
            next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // stop one before middle, so we can disconnect later
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;   // disconnect

        return second;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        
        // split and return middle 
        ListNode* secondList = findMiddle(head);

        // reverse
        secondList = reverse(secondList);

        // merge
        mergeAlternate(head, secondList);

        return;
    }
};