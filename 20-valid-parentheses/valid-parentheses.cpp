class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char c : s) {
            // pop
            if(c == ')' || c == ']' || c == '}') {
                // safety 
                if(stk.empty()) {
                    return false;
                }
                else if(stk.top() == '(' && c == ')') {
                    stk.pop();
                }
                else if(stk.top() == '[' && c == ']') {
                    stk.pop();
                }
                else if(stk.top() == '{' && c == '}') {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
            // insert
            else {
                stk.push(c);
            }
        }

        if(stk.size() != 0) {
            return false;
        }

        return true;
    }
};