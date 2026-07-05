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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0, head);

        ListNode* prevGroup = dummy;
        ListNode* nextGroup = nullptr;

        ListNode* firstNode = head;
        ListNode* KthNode = nullptr;

        ListNode* curr = head;

        while (curr) {

            // reach kth node
            for (int i = 1; i < k; i++) {
                if (curr == nullptr || curr->next == nullptr)
                    return dummy->next;

                curr = curr->next;
            }

            // set variables
            KthNode = curr;
            nextGroup = curr->next;

            // break link
            curr->next = nullptr;

            ListNode* reversedHead = reverse(firstNode);

            // link back
            prevGroup->next = reversedHead;
            firstNode->next = nextGroup;

            // move ahead
            prevGroup = firstNode;
            firstNode = nextGroup;
            curr = nextGroup;
        }

        return dummy->next;
    }
};