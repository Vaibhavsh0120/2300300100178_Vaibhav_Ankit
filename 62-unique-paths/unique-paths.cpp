class Solution {
public: 
    vector<vector<int>> dp;

    int solve(int i, int m, int j, int n) {
        // base case
        if(i == m - 1 && j == n - 1) {
            return 1;
        }

        // memo
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // move right
        int right = 0;
        if(i < m) {
            right = solve(i + 1, m, j , n);
        }

        // move down
        int down = 0;
        if(j < n) {
            down = solve(i, m, j + 1, n);
        }

        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        dp.assign(m + 1, vector<int>(n + 1, -1));

        return solve(0, m, 0, n);
    }
};