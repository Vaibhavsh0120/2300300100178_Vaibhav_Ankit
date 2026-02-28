class Solution {
public:
    // Helper function to check if we can place k cows with a minimum distance of `dist`
    bool canPlace(vector<int>& stalls, int k, int dist) {
        int cows = 1; // Always place the first cow in the first stall
        int lastPlaced = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPlaced >= dist) {
                cows++;
                lastPlaced = stalls[i];
            }
            if (cows == k) {
                return true; // We successfully placed all k cows
            }
        }
        return false;
    }

    // Binary Search on Answer: O(N log N + N * log(Max-Min)) time, O(1) space
    int aggressiveCows(vector<int> &stalls, int k) {
        // Sort stalls to place cows consecutively with maximum minimum-distance
        sort(stalls.begin(), stalls.end());

        int low = 1; // Minimum possible distance
        int high = stalls.back() - stalls.front(); // Maximum possible distance
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Check if `mid` can be the minimum distance

            if (canPlace(stalls, k, mid)) { // If we can place cows with at least `mid` distance
                ans = mid; // This is a valid answer, store it
                low = mid + 1; // Try for a larger distance
            } else {
                high = mid - 1; // `mid` distance is too large, try smaller distance
            }
        }
        return ans;
    }
};