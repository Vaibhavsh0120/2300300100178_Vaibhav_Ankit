class Solution {
public:
    // Prefix Sum + Hash Map Approach: O(n) time, O(n) space
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> subNum; // Maps prefix sum to its frequency
        subNum[0] = 1; // Base case: a prefix sum of 0 occurs once
        int total = 0; // Current prefix sum
        int count = 0; // Number of valid subarrays

        for (int n : nums) {
            total += n;

            // If (total - k) exists in map, it means there is a subarray ending here with sum k
            if (subNum.find(total - k) != subNum.end()) {
                count += subNum[total - k];
            }

            // Increment frequency of current prefix sum
            subNum[total]++;
        }

        return count;
    }
};