class Solution {
public:
    int solve(int i, string &text1, int j, string &text2, vector<vector<int>>& dp) {
        // BASE CASE
        if(i == text1.size() || j == text2.size()) {
            return 0;
        }

        // DP
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        // TAKE, NOT TAKE
        if(text1[i] == text2[j]) { // if same, move both
            return dp[i][j] = 1 + solve(i + 1, text1, j + 1, text2, dp);
        }

        return dp[i][j] = max(   // if not same, try moving either one of them and choose max
            solve(i + 1, text1, j, text2, dp),
            solve(i, text1, j + 1, text2, dp)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(), -1));
        return solve(0, text1, 0, text2, dp);
    }
};