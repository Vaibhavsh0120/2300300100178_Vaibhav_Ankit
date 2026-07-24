class Solution {
public:
    vector<int> dp;

    int solve(int n) {
        // base 
        if (n == 1) {
            return 1;
        }

        // dp
        if(dp[n] != -1) {
            return dp[n];
        }

        // working
        int maxProd = INT_MIN;
        for(int i = 1 ; i < n ; i++) {
            maxProd = max(maxProd, i * max(n - i, solve(n - i)));
        }

        return dp[n] = maxProd;
    }

    int integerBreak(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};