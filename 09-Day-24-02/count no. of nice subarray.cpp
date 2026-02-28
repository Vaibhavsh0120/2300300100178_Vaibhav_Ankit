// Note: Contains both C++ and Java implementations.

// Personal Approach (C++): Prefix Sum with frequency array
// O(n) time, O(n) space
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0); // Frequency array to store odd counts
        cnt[0] = 1;
        int ans = 0, t = 0;
        
        for (int v : nums) {
            t += v & 1; // Increment running count if current number is odd
            if (t - k >= 0) {
                ans += cnt[t - k]; // Add number of valid subarrays
            }
            cnt[t]++;
        }
        return ans;
    }
};


// Instructor's Approach (Java): Sliding Window
// O(n) time, O(1) space
/*
class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length; 
        int count = 0;
        int i = 0, j = 0, curr_Sum = 0, Zero_Count = 0;
        
        while (j < n) {
            curr_Sum = curr_Sum + nums[j] % 2;
            
            while (i < j && (curr_Sum > k || nums[i] % 2 == 0)) {
                if (nums[i] % 2 == 1) {
                    Zero_Count = 0;
                } else {
                    Zero_Count++;
                }
                curr_Sum -= nums[i] % 2;
                i++;
            }

            if (curr_Sum == k) {
                count = count + 1 + Zero_Count;
            }
            j++;
        }
        return count;
    }
}
*/