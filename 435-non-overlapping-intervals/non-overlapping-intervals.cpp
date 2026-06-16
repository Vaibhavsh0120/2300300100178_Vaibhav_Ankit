class Solution {
public:
    static bool compair(vector<int> a, vector<int> b) {
        return a[1] < b[1]; // increasing order of end time
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int overlaps = 0;
        
        sort(intervals.begin(), intervals.end(), compair);

        int currTime = INT_MIN;

        for(int i = 0 ; i < intervals.size() ; i++) {
            if(currTime <= intervals[i][0]) {
                currTime = intervals[i][1];
            }
            else {
                overlaps++;
            }
        }

        return overlaps;
    }
};