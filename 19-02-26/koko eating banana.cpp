class Solution {
public:
    // Binary Search on Answer: O(N log(Max Piles)) time, O(1) space
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; // Minimum eating speed (1 banana/hour)
        int r = *max_element(piles.begin(), piles.end()); // Maximum eating speed (largest pile)
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2; // Current eating speed candidate
            
            // Use long long to prevent overflow
            long long hours = 0; 
            
            // Calculate total hours required to eat all bananas at speed `mid`
            for (int p : piles) {
                hours += (p + mid - 1) / mid; // Equivalent to ceil((double)p / mid)
            }

            // If koko can eat all bananas within `h` hours, try a slower speed
            if (hours <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                // If it takes more than `h` hours, she needs to eat faster
                l = mid + 1;
            }
        }

        return ans;
    }
};