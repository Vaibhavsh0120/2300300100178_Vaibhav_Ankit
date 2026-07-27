class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // BASE CASE already handled (initialized with 0)

        // i = 1, INDEX = 0 - for this question for -1 safety
        // j = 1, INDEX = 0
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                // converted i and j to normal to access string
                // when char match move both and count 1 length
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                // else move both i and j, one at a time
                else {
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
                }
            }
        }

        return dp[m][n];
    }
};