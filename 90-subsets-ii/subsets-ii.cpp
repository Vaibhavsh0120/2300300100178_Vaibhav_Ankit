class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& result) {
        if(i >= nums.size()) {
            result.push_back(curr);
            return;
        }

        // take
        curr.push_back(nums[i]);
        solve(i + 1, nums, curr, result);
        curr.pop_back();

        // skip duplicates
        int j = i;
        while(j + 1 < nums.size() && nums[j] == nums[j + 1]) {
            j++;
        }

        // not take
        solve(j + 1, nums, curr, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;

        sort(nums.begin(), nums.end());

        solve(0, nums, curr, result);

        return result;
    }
};