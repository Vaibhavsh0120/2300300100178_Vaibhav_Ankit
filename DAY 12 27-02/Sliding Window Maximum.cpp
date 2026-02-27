class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
            // BRUTE FORCE - TLE
            // vector<int> result;
    
            // if(nums.size() <= k) {
            //     int maxi = *max_element(nums.begin(), nums.end());
            //     result.push_back(maxi);
    
            //     return result;
            // }
            
            // int left = 0;
    
            // for(int right = k-1 ; right < nums.size() ; right++){
    
            //     int maxi = *max_element(nums.begin() + left, nums.begin() + right + 1);
    
            //     result.push_back(maxi);
    
            //     left++;
            // }
    
            // return result;
    
            int n = nums.size();
            vector<int> ans;
    
            multiset<pair<int,int>> st;   // {value, index}
            int left = 0;
    
            for (int right = 0; right < n; right++) {
    
                st.insert({nums[right], right});
    
                // Remove elements outside window
                while (!st.empty() && st.begin()->second < right - k + 1) {
                    st.erase(st.begin());
                }
    
                if (right - left + 1 > k) {
                    st.erase(st.find({nums[left], left}));
                    left++;
                }
    
                if (right - left + 1 == k) {
                    ans.push_back(st.rbegin()->first);  // max value
                }
            }
    
            return ans;
        }
    };