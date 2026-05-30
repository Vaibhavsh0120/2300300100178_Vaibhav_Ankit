class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> window;
        int L = 0;

        for (int R = 0; R < nums.size(); R++) {
            if (R - L > k) {
                window.erase(nums[L]);
                L++;
            }

            if (window.count(nums[R])) {
                return true;
            }

            window.insert(nums[R]);
        }

        return false;
    }
};