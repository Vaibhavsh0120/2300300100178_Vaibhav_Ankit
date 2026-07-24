class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> soln;

        // number, frequency
        unordered_map<int, int> mp;

        for(int i = 0 ; i < nums.size() ; i++) {
            mp[nums[i]]++;

            // if number is coming again
            if(mp[nums[i]] >= 2) {
                soln.insert(nums[i]);
            }
        }

        vector<int> ans(soln.begin(), soln.end());

        return ans;
    }
};