class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;

        vector<int> result;
        k = k % nums.size();

        int pos = (nums.size() - k) % nums.size();

        for (int i = 0; i < nums.size(); i++) {
            result.push_back(nums[pos]);
            pos = (pos + 1) % nums.size();
        }

        nums = result;
    }
};