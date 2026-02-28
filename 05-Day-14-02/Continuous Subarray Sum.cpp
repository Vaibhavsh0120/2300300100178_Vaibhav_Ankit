class Solution {
public:
    // Prefix Sum + Hash Map Approach: O(n) time, O(min(n, k)) space
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Map to store (prefix_sum % k) and its earliest index
        unordered_map<int, int> mp;
        mp[0] = -1; // Base case: To handle subarray starting from index 0
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remainder = sum % k;
            
            // If the same remainder was seen before, it means the elements in between sum to a multiple of k
            if (mp.find(remainder) != mp.end()) {
                // Check if the subarray length is at least 2
                if (i - mp[remainder] >= 2) return true;
            } else {
                // Only store the first occurrence to maximize the subarray length
                mp[remainder] = i;
            }
        }
        return false;
    }
};