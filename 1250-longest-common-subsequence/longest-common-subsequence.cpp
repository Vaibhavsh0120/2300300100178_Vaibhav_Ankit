class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, string &text1, int j, string &text2) {
        // base case
        if(i == text1.size() || j == text2.size()) {
            return 0;
        }

        // memo
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // move both if same
        int both = 0;
        if(text1[i] == text2[j]) {
            // "1 +" to count length
            both = 1 + solve(i + 1, text1, j + 1, text2);
        }

        // try move one, select which gives largest result
        int single = max(
            solve(i + 1, text1, j, text2),
            solve(i, text1, j + 1, text2)
        );

        return dp[i][j] = max(single, both);
    }

    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size() + 1, vector<int>(text2.size() + 1, -1));

        return solve(0, text1, 0, text2);
    }
};