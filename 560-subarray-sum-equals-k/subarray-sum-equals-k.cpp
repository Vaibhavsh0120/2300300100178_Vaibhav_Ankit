class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Store prefixSum in the hashmap
        
        int count = 0;

        unordered_map<int, int> mp;
        int prefixSum = 0;

        mp[0] = 1;

        for(int n : nums) {
            // calculate prefixsum
            prefixSum += n;

            // check in hashmap
            if(mp.count(prefixSum - k)) {
                count+= mp[prefixSum - k];
            }

            // update hashmap
            mp[prefixSum]++;
        }

        return count;
    }
};