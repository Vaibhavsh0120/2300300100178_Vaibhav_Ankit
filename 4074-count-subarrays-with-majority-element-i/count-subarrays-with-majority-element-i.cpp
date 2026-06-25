class Solution {
public:

    int countMajoritySubarrays(vector<int>& nums, int target) { 
        int ans = 0;

        int currCount = 0;
        int targetCount = 0;

        for(int i = 0 ; i < nums.size() ; i++) {

            currCount = 0;
            targetCount = 0;

            for(int j = i ; j < nums.size() ; j++) {
                currCount++;

                if(nums[j] == target) {
                    targetCount++;
                }

                if(currCount/2 < targetCount) {
                    ans++;
                }
                
            }
        }

        return ans;
    }
};