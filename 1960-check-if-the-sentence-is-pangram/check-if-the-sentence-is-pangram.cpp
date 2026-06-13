class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> st;

        for(char c : sentence) {
            st.insert(c);
        }

        if(st.size() == 26) {
            return true;
        }

        return false;
    }
};