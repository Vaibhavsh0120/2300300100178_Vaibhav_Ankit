class Solution {
public:
    // Tracking Array Approach: O(n) time, O(1) space
    int numberOfSubstrings(string s) {
        int count = 0;
        int lastSeen[3] = {-1, -1, -1}; // Tracks the last seen index for 'a', 'b', and 'c'

        for (int i = 0; i < s.size(); i++) {
            lastSeen[s[i] - 'a'] = i;  // Converts 'a' -> 0, 'b' -> 1, 'c' -> 2
            
            // If all 3 characters have been seen at least once
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                // The number of valid substrings ending at 'i' corresponds to the 
                // index of the character that was seen the earliest among the three
                int earliest_index = min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
                count += (1 + earliest_index);

                // Explanation:
                // For a substring ending at 'i', we need it to contain 'a', 'b', 'c'.
                // Any starting point from 0 up to `earliest_index` will contain all three characters.
                // Thus, there are `earliest_index - 0 + 1 = earliest_index + 1` valid substrings ending at `i`.
            }
        }

        return count;
    }
};