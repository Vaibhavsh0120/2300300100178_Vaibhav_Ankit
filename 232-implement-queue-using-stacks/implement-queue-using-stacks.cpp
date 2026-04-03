struct Node {
    int val;
    Node *next;

    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class MyQueue {
private:
    Node* front;
    Node* back;

public:
    MyQueue() {
        front = nullptr;
        back = nullptr;
    }

    void push(int x) {
        Node* temp = new Node(x);

        if (back == nullptr) {      // queue empty
            front = temp;
            back = temp;
        } 
        else {
            back->next = temp;
            back = temp;
        }
    }

    int pop() {
        int value = front->val;

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {     // queue became empty
            back = nullptr;
        }

        return value;
    }

    int peek() {
        return front->val;
    }

    bool empty() {
        return front == nullptr;
    }
};