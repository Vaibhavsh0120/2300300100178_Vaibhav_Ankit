class Solution {
public:
    int helper(int i, vector<int>& nums, int maxCur, int maxx) {
        if(i == nums.size()) {
            return maxx;
        }

        // if strictly increasing
        if(nums[i -1] < nums[i]) {
            maxCur++;
            maxx = max(maxx, maxCur);
            return helper(i+1, nums, maxCur, maxx);
        }
        else {
            maxCur = 1;
            return helper(i+1, nums, maxCur, maxx);
        }
    }
    int findLengthOfLCIS(vector<int>& nums) {
        return helper(1, nums, 1, 1);
    }
};