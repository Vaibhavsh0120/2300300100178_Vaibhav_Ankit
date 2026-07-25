class Solution {
public:

    vector<int> dp;

    int combinationSum4(vector<int>& nums, int target) {
        // init dp first time
        if(dp.size() == 0) {
            dp.assign(target + 1, -1);
        }

        // correct case
        if(target == 0) {
            return 1;
        }

        // wrong case
        if(target < 0) {
            return 0;
        }

        // memo
        if(dp[target] != -1) {
            return dp[target];
        }

        // working
        long long ans = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            ans += combinationSum4(nums, target - nums[i]);
        }

        // return
        return dp[target] = ans; 
    }
};