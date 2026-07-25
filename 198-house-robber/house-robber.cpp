class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& nums) {
        // base case
        if(i >= nums.size()) {
            return 0;
        }

        // dp
        if(dp[i] != -1) {
            return dp[i];
        }

        // working
        int take = nums[i] + solve(i + 2, nums);
        int notTake = solve(i + 1, nums);

        // return
        return dp[i] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        dp.assign(nums.size() + 1, -1);
        return solve(0, nums);
    }
};