class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;

        // all possible subarray
        for(int i = 0 ; i < nums.size() ; i++) {
            int currSum = 0;
            for(int j = i ; j < nums.size() ; j++) {
                currSum += nums[j];

                // if curr subarray have sum == k
                if(currSum == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};