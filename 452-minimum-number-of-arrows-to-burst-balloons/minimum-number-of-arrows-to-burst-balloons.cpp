class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end()); // sort on the basis of increasing starting point

        vector<int> prev = points[0];   // first balloon as prev

        int count_arrows = 1; // minimum 1 arrow will require for prev

        for(int i = 1 ; i < points.size() ; i++) {
            int currStart = points[i][0];
            int currEnd = points[i][1];

            int prevStart = prev[0];
            int prevEnd = prev[1];

            // check overlap
            if(prevEnd < currStart) {
                // NO OVERLAP
                count_arrows++; // we need 1 more arrow for non overlap arrow
                prev = points[i];
            }
            else {
                // OVERLAP
                // Assume the overlapping section as the one balloon

                prev[0] = max(currStart, prevStart);
                prev[1] = min(currEnd, prevEnd);

                // no need to increase arrow cause overlap
            }
        }

        return count_arrows;
    }
};