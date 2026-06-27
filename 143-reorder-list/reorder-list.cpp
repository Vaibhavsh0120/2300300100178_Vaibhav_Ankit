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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        vector<int> v;
        // to vector
        while(curr) {
            v.push_back(curr->val);
            curr = curr->next;
        }

        // work

        int i = 0;
        int j = v.size() - 1;

        vector<int> ans;
        while(i <= j) {
            ans.push_back(v[i]);
            ans.push_back(v[j]);
            i++;
            j--;
        }

        // to linked list
        i = 0;
        curr = head;
        while(curr) {
            curr->val = ans[i];
            i++;
            curr = curr->next;
        }

        return;
    }
};