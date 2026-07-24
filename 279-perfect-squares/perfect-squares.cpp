class Solution {
public:
    vector<int> dp;

    int solve(int n) {
        // base case
        if(n == 0) {
            return 0;
        }

        // memorization
        if(dp[n] != -1) {
            return dp[n];
        }

        // working
        int ans = INT_MAX;
        for(int i = 1 ; i * i <= n ; i++) {
            ans = min(ans, 1 + solve(n - i * i));
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};