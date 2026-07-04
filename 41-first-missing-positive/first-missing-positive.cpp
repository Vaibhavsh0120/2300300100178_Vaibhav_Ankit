class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // SOLN 1

        sort(nums.begin(), nums.end());

        int missing = 1;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] > 0 && nums[i] == missing) { // if number is +ve and we find it in array
                missing++;
            }
        }

        return missing;
    }
};