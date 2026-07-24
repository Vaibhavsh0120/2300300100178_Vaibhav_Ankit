class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < s.size(); r++) {
            // Add current character
            mp[s[r]]++;

            // Remove duplicates
            while (mp[s[r]] > 1) {
                mp[s[l]]--;
                l++;
            }

            // Update answer
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};