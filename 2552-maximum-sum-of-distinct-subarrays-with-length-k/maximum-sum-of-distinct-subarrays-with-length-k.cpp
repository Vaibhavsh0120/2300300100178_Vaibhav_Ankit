class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // sliding window and hashmap

        // number, freq
        unordered_map<int, int> mp;

        long long sum = 0;
        long long maxSum = 0;

        int left = 0;

        for(int right = 0 ; right < nums.size() ; right++) {
            // add new element
            sum += nums[right];
            mp[nums[right]]++;

            // check if not within window size
            if(right - left + 1 > k) {
                // remove from sum
                sum -= nums[left];

                // remove from hashmap
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }

                // move left ptr
                left++;
            }

            // if correct window size and distinct
            if(right - left + 1 == k && mp.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};