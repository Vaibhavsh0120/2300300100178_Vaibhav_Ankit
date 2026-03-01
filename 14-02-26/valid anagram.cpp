// Sorting approach: O(n log n) time, O(1) space (excluding sort stack)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Frequency array approach: O(n) time, O(1) space (26 characters only)
class OptimalSolution {
public:
    bool isAnagram(string s, string t) {
        // If lengths differ, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        
        vector<int> freq(26, 0); // Array to store frequency of a-z characters
        
        // Count occurrences of characters in s and subtract for t
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        // If any frequency is non-zero, they don't have exactly the same characters
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};