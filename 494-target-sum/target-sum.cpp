class Solution {
public:
    // new form of dp
    vector<unordered_map<int,int>> dp;

    int ways(int i, vector<int>& nums, int target) {
        // Base case
        if(i == nums.size() && target == 0) {
            return 1;
        }

        if(i == nums.size() && target != 0) {
            return 0;
        }

        // Memoization
        if (dp[i].count(target)) {
            return dp[i][target];
        }

        // Recursive calls
        int posi = ways(i+1, nums, target + nums[i]);
        int nega = ways(i+1, nums, target - nums[i]);

        // Store and return
        return dp[i][target] = posi + nega;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.resize(nums.size());

        return ways(0, nums, target);
    }
};