class Solution {
public:
    vector<int> dp;

    int helper(int i, vector<int>& nums){
        // base case
        if(i >= nums.size()) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int taken = nums[i] + helper(i+2, nums);
        int notTaken = helper(i+1, nums);

        return dp[i] = max(taken, notTaken);
    }

    int rob(vector<int>& nums) {
        dp.assign(nums.size() + 1, -1);
        return helper(0, nums);
    }
};