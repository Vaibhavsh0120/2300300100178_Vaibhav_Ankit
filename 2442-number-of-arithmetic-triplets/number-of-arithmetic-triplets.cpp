class Solution {
public:
    int arithmeticTriplets_OPTIMIZED(vector<int>& nums, int diff) {
        /*
            Here the conditions are:
            nums[j] - nums[i] = diff
            nums[k] - nums[j] = diff

            or equivalently:
            nums[k] = nums[i] + 2 * diff
        */

        unordered_set<int> st(nums.begin(), nums.end());

        int count = 0;

        for (int x : nums) {
            // IF x, x + diff, x + 2 * diff exist -> solution
            if (st.count(x + diff) && st.count(x + 2 * diff)) {
                count++;
            }
        }

        return count;
    }

    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                // CONDITION 1 SATISFIED
                if (nums[j] - nums[i] == diff) {
                    for (int k = j + 1; k < nums.size(); k++) {
                        // CONDITION 2 SATISFIED
                        if (nums[k] - nums[j] == diff) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};