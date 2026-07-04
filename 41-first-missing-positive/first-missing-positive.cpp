class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // SOLN 2 TIME O(N) - SPACE O(N)

        unordered_set<int> st(nums.begin(), nums.end());

        int missing = -1;

        // smallest +ve ans ; what is array is natural number
        for(int i = 1 ; i < nums.size() + 1 ; i++) {
            if(!st.count(i)) { // number not found in set
                missing = i;
                break;
            }
        }

        // if array is natural number
        if(missing == -1) {
            missing = nums.size() + 1;
        }

        return missing;
    }
};