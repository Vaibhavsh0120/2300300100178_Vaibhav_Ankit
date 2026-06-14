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
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = left + 1;

            while (left < n && right < n) {

                if (nums[left] - nums[i] < diff) {
                    left++;
                    if (right <= left)
                        right = left + 1;
                }
                else if (nums[left] - nums[i] > diff) {
                    break;
                }
                else {
                    // first condition satisfied
                    if (nums[right] - nums[left] < diff) {
                        right++;
                    }
                    else if (nums[right] - nums[left] > diff) {
                        left++;
                        if (right <= left)
                            right = left + 1;
                    }
                    else {
                        count++;
                        left++;
                        right++;
                    }
                }
            }
        }

        return count;
    }
};