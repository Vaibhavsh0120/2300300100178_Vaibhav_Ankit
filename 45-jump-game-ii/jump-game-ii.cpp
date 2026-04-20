class Solution {
public:
    int jump(vector<int>& nums) {
        // GREEDY APPROACH USING RANGES - STRIVER
        int jumps = 0;
        int l = 0, r = 0;

        while (r < nums.size() - 1) {

            int farthest = 0; // Farthest from that index

            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1; // least possible to reach within next jump (which we tried all above)
            r = farthest; // most possible to reach within next jump
            // RANGE SET FOR POSSIBLE REACHES FOR NEXT JUMP
            jumps++; // TAKE JUMP - THEN TRY ALL THE POSSIBLE JUMP RANGE FROM THERE
        }

        return jumps;
    }
};