class Solution {
public:
    // Multiset Approach: O(n log k) time, O(k) space
    // Note: Can be optimized to O(n) time using a Deque (Double Ended Queue).
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
        // BRUTE FORCE - O(n*k) - TLE
        vector<int> result;
        if(nums.size() <= k) {
            int maxi = *max_element(nums.begin(), nums.end());
            result.push_back(maxi);
            return result;
        }
        int left = 0;
        for(int right = k-1 ; right < nums.size() ; right++){
            int maxi = *max_element(nums.begin() + left, nums.begin() + right + 1);
            result.push_back(maxi);
            left++;
        }
        return result;
        */

        int n = nums.size();
        vector<int> ans;

        // Stores {value, index}. Storing value helps maintain order.
        multiset<pair<int, int>> st;   
        int left = 0;

        for (int right = 0; right < n; right++) {
            st.insert({nums[right], right});

            // Remove elements whose index is outside the current window
            while (!st.empty() && st.begin()->second < right - k + 1) {
                st.erase(st.begin());
            }

            // Keep window size bounded at k by explicitly removing the oldest element
            if (right - left + 1 > k) {
                auto it = st.find({nums[left], left});
                if (it != st.end()) {
                    st.erase(it);
                }
                left++;
            }

            // Once the window has reached size k, the largest element is at the end of the multiset
            if (right - left + 1 == k) {
                ans.push_back(st.rbegin()->first);  // rbegin gives the largest value
            }
        }

        return ans;
    }
};