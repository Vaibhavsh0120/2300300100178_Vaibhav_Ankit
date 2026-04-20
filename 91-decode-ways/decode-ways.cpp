class Solution {
public:
    int t[101]; // memoization

    int solve(int i, string &s) {
        if(t[i] != -1) { // memoization
            return t[i];
        }

        if(i == s.size()) {
            return t[i] = 1; // Valid Split found
        }

        if(s[i] == '0') {
            return t[i] = 0; // Split not possible
        }

        int single_char = solve(i + 1, s);

        int double_char = 0;
        if(i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
        // Out-Of-Bound Safe    first 1          first 2 , second less than 7 to be valid alphabet 
            double_char = solve(i + 2, s);
        }

        return t[i] = single_char + double_char; // memoization first
    }

    int numDecodings(string s) {
        memset(t, -1, sizeof(t));
        return solve(0, s);
    }
};