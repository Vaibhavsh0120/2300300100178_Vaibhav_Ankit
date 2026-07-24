class Solution {
public:
    vector<int> dp;

    int solve(int n) {
        // base case
        if(n <= 0) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 1;
        }

        // Memoization
        if (dp[n] != -1) {
            return dp[n];
        }

        // working
        return dp[n] = solve(n - 3) + solve(n - 2) + solve(n - 1);
    }

    int tribonacci(int n) {
        dp.assign(n + 1, -1);

        return solve(n);
    }
};