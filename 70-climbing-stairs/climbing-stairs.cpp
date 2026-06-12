class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n == 1 || n == 2) { // valid jump which reach end
            return n;   // no of possible sequence
        }

        if(n <= 0) {    // invalid jump
            return 0;
        }

        // dp
        if (dp[n] != -1) {
            return dp[n];
        }

        int jump = solve(n - 1, dp);

        int longjump = solve(n -2, dp);

        return dp[n] = jump + longjump;
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};