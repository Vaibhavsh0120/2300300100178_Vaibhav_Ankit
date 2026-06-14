class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        /*
            [-4, -1, -1, 0, 1, 2]
              |   |            |
              i  left->     <-right   // if i + left + right = 0 SOLN
        */

        // NOTE: Keep i, left, right safe from duplicates

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) // SKIP curr if prev elt is same [no duplicates]
                continue;                        // Except at i = 0, then dont skip

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // one answer found
                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // if duplicate skip left
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // if duplicate skip right
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } 
                // if need to add more to become 0, move left (leave smaller value)
                else if (sum < 0) {
                    left++;
                } 
                // if need to subtract more to become 0, move right (leave larger value)
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};