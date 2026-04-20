class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Greedy Approach

        int maxIndexReached = 0;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(i > maxIndexReached) {
                return false;
            }

            int currReach = i + nums[i];
            maxIndexReached = max(maxIndexReached, currReach);
        }

        return true;
    }
};