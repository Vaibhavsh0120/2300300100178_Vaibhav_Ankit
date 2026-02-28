class Solution {
public:
    // Hash Map Approach: O(n) time, O(n) space
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pairIdx; // Maps number to its index

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            // Check if the complement exists in the map
            if (pairIdx.find(target - num) != pairIdx.end()) {
                return {i, pairIdx[target - num]};
            }
            // Add current number and its index to the map
            pairIdx[num] = i;
        }

        return {}; // Return empty if no valid pair is found
    }
};