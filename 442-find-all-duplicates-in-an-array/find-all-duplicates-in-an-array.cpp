class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // all element of nums are +ve and appear atmost twice
        vector<int> soln;

        for(int i = 0 ; i < nums.size() ; i++) {
            int index = abs(nums[i]) - 1;

            // if duplicate
            if(nums[index] < 0) {
                soln.push_back(abs(nums[i]));
            }
            // else not duplicate, make that index as -ve to sign we have found it
            else {
                nums[index] *= -1;
            }
        }

        return soln;
    }
};