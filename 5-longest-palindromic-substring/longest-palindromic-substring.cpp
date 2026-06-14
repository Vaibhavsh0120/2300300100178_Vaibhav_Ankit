class Solution {
public:
    // memoization
    int dp[1001][1001];

    bool checkPalindrome(int i, int j, string& s) {
        if(j <= i) {
            return dp[i][j] = 1;
        }

        // DP
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i] == s[j]) {
            return dp[i][j] = checkPalindrome(i+1, j-1, s);
        }

        return dp[i][j] = 0;
    }

    string longestPalindrome(string s) {
        string longest = s.substr(0, 1); // EDGE CASE: if only 1 character
        memset(dp, -1, sizeof(dp));
        /* FILL DP ARRAY BY -1
            memset(dp, -1, sizeof(dp));
                    |    |        |
                    |    |        total bytes of dp
                    |    value to fill
                    memory address
        */

        for(int i = 0 ; i < s.size() ; i++) {
            for(int j = i + 1 ; j < s.size() ; j++) {
                // check if the possible substring is palindrome
                if(checkPalindrome(i, j, s)) {
                    // check if the palindrome string is longest
                    if(longest.size() < j-i+1) {
                        // s.substr(start, length)
                        longest = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return longest;
    }
};