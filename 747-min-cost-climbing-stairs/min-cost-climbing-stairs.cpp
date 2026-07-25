class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& cost) {
        // base case
        if(i >= cost.size()) {
            return 0;
        }

        // memo
        if(dp[i] != -1) {
            return dp[i];
        }

        // try one step
        int one = cost[i] + solve(i+1, cost);

        // try two step
        int two = cost[i] + solve(i+2, cost);

        return dp[i] = min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // start from 0 index
        dp.assign(cost.size() + 1, -1);
        int one = solve(0, cost);

        // start from 1 index
        dp.assign(cost.size() + 1, -1);
        int two = solve(1, cost);

        return min(one, two);
    }
};