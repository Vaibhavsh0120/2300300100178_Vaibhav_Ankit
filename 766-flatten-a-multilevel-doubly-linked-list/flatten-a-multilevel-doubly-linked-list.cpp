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
        if (head == nullptr)
            return nullptr;

        vector<int> v; // save answer
        stack<Node*> stk;

        // to save node if child found
        stk.push(head);

        while (!stk.empty()) {
            Node* curr = stk.top();
            stk.pop();

            // keep continue forward and down
            while (curr) {
                // Keep pushing curr
                v.push_back(curr->val);
                
                // if curr has child, save next in stack
                if (curr->child) {
                    if (curr->next) {
                        stk.push(curr->next);
                    }
                    
                    // go to that child
                    curr = curr->child;
                } else {
                    // keep continue till nullptr
                    curr = curr->next;
                }
            }

            // layer remain in stack, it will continue
        }

        // create new Linked List according to Vector
        Node* newHead = new Node();
        newHead->val = v[0];
        newHead->prev = nullptr;
        newHead->next = nullptr;
        newHead->child = nullptr;

        Node* curr = newHead;

        for (int i = 1; i < v.size(); i++) {
            //setup new node
            Node* temp = new Node();
            temp->val = v[i];
            temp->prev = curr;
            temp->next = nullptr;
            temp->child = nullptr;

            // set and move prev node
            curr->next = temp;
            curr = temp;
        }

        return newHead;
    }
};