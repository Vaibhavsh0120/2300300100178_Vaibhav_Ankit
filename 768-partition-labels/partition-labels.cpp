class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp; // last occurrence of each character

        // Store last occurrence
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }

        vector<int> soln;

        for (int i = 0; i < s.size();) {

            int start = i;
            int end = mp[s[i]];

            // Expand the current partition
            for (int j = start; j <= end; j++) {
                end = max(end, mp[s[j]]);
            }

            // Store partition length
            soln.push_back(end - start + 1);

            // Move to next partition
            i = end + 1;
        }

        return soln;
    }
};