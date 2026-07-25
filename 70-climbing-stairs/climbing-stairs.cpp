class Solution {
public:
    vector<int> dp;

    int climbStairs(int n) {
        // make dp if not exist
        if (dp.empty()) {
            dp.assign(n + 1, -1);
        }

        // base case
        if(n == 1 || n == 2) {
            return n;
        }

        // memo
        if(dp[n] != -1) {
            return dp[n];
        }

        // return
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};