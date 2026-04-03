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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    // EDGE CASE
    if(list1 == nullptr && list2 == nullptr) {
        return nullptr;
    }

    if(list1 == nullptr) { 
        return list2;
    }
    if(list2 == nullptr) {
        return list1;
    } 

    // MERGE
    ListNode* head = new ListNode();
    ListNode* move = head;
    
    while(list1 != nullptr && list2 != nullptr) {
        if(list1->val < list2->val) {
            ListNode* temp = new ListNode(list1->val);
            list1 = list1->next;
            move->next = temp;
        } else {
            ListNode* temp = new ListNode(list2->val);
            list2 = list2->next;
            move->next = temp;
        }

        move = move->next;
    }

    while(list1 != nullptr) {
        ListNode* temp = new ListNode(list1->val);
        list1 = list1->next;
        move->next = temp;
        move = move->next;
    }

    while(list2 != nullptr) {
        ListNode* temp = new ListNode(list2->val);
        list2 = list2->next;
        move->next = temp;
        move = move->next;
    }

    return head->next;
        
    }
};