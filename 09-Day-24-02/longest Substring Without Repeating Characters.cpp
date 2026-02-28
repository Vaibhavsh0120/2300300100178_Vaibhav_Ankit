class Solution {
public:
    // Sliding Window with Hash Set: O(n) time, O(min(n, m)) space 
    // where m is the size of the charset.
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_set<char> charSet;

        // Expand the right side of the window
        for (int right = 0; right < s.length(); right++) {
            // Shrink the window from the left if we encounter a repeating character
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            // Add the new valid character to the set
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;        
    }
};