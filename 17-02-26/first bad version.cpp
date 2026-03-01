// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // Binary Search Approach: O(log n) time, O(1) space
    int firstBadVersion(int n) {
        int l = 1, h = n; // Note: usually versions start at 1, so l should be 1
        
        while (l <= h) {
            int mid = l + (h - l) / 2; // Prevents overflow compared to (l + h) / 2
            
            if (isBadVersion(mid)) {
                // If mid is bad, the first bad version is at mid or before it
                h = mid - 1;
            } else {
                // If mid is good, the first bad version is strictly after mid
                l = mid + 1;
            }
        }
        
        // l ends up pointing to the first bad version
        return l;
    }
};