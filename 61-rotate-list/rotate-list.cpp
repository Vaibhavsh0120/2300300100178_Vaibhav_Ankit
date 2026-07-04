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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head) {
            return head;
        }
        
        // LL to V
        vector<int> v;
        ListNode* cur = head;

        while(cur) {
            v.push_back(cur->val);
            cur = cur->next;
        }

        // working

        vector<int> soln;
        k = k % v.size(); // safety
        int i = v.size() - k; // starting index
        while(soln.size() != v.size()) {
            i = i % v.size();
            soln.push_back(v[i]);
            i++;
        }

        // back to LL

        i = 0;
        cur = head;
        while(cur) {
            cur->val = soln[i];
            i++;
            cur = cur->next;
        }

        return head;
         
    }
};