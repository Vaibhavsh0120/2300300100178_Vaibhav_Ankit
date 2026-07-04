/*
 // Definition for a Node.
 class Node {
 public:
     int val;
     Node* prev;
     Node* next;
     Node* child;
 };
*/

class Solution {
public:
    Node* flatten(Node* head) {
        // if empty
        if (head == nullptr) {
            return nullptr;
        }

        vector<int> v;
        stack<Node*> stk;

        stk.push(head);

        while (!stk.empty()) {
            // continue after child
            Node* curr = stk.top();
            stk.pop();

            // continue forward
            while (curr) {
                v.push_back(curr->val);

                //if child, save next in start
                if (curr->child) {
                    if (curr->next) {
                        stk.push(curr->next);
                    }

                    curr = curr->child;
                } 
                // else keep moving forward
                else {
                    curr = curr->next;
                }
            }
        }

        // New Linked List Head
        Node* newHead = new Node();
        newHead->val = v[0];
        newHead->prev = nullptr;
        newHead->next = nullptr;
        newHead->child = nullptr;

        Node* curr = newHead;

        // fill that linked list with vector
        for (int i = 1; i < v.size(); i++) {
            Node* temp = new Node();
            temp->val = v[i];
            temp->prev = curr;
            temp->next = nullptr;
            temp->child = nullptr;

            curr->next = temp;
            curr = temp;
        }

        return newHead;
    }
};