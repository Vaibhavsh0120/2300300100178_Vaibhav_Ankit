class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Count frequency
        for (int num : nums) {
            mp[num]++;
        }

        // Store {frequency, number}
        vector<pair<int, int>> freq;

        for (auto &it : mp) {
            freq.push_back({it.second, it.first});
        }

        // Sort by frequency (descending)
        sort(freq.begin(), freq.end(), greater<pair<int, int>>());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].second);
        }

        return ans;
    }
};