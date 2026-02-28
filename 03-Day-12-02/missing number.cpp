class Solution {
public:
    // Hashing approach: O(n) time, O(n) space
    // Note: Can also be solved in O(1) space using Math (Sum of n natural numbers - sum of array) or XOR.
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n + 1, -1); // Extra array to mark presence of numbers
        
        // Mark numbers present in the input array
        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]] = nums[i];
        }
        
        // Find the first unmarked index, which is the missing number
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == -1) {
                return i;
            }
        }
        return 0;
    }
};