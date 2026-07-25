class Solution {
public:
    vector<int> dp;

    int solve(int i, const vector<int>& nums) {
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
        // single element edge case
        if(nums.size() == 1) {
            return nums[0];
        }
        
        dp.assign(nums.size() + 1, -1);
        int withoutFirst = solve(0, vector<int>(nums.begin() + 1, nums.end()));

        dp.assign(nums.size() + 1, -1);
        int withoutLast = solve(0, vector<int>(nums.begin(), nums.end() - 1));

        return max(withoutFirst, withoutLast);
    }
};