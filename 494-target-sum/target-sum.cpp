class Solution {
public:
    // wont work cause target can be -ve
    // vector<vector<int>> dp;
    vector<unordered_map<int, int>> dp;

    int solve(int i, vector<int>& nums, int target) {
        // base
        if(i == nums.size()) {
            return target == 0 ? 1 : 0;
        }

        // hashmap dp
        if(dp[i].count(target)) {
            return dp[i][target];
        }

        int posi = solve(i + 1, nums, target + nums[i]);
        int nega = solve(i + 1, nums, target - nums[i]);

        return dp[i][target] = posi + nega;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.resize(nums.size() + 1);

        return solve(0, nums, target);
    }
};