class Solution {
public:
    bool permutationCheck(unordered_map<char, int> original, unordered_map<char, int> mixed) {
        for(auto kv : original) {
            if(original[kv.first] != mixed[kv.first]) {
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.size();

        unordered_map<char, int> original, mixed;

        for(int i = 0 ; i < s1.size() ; i++) {
            original[s1[i]]++;
        }

        int maxSize = 0;
        int l = 0;

        for(int r = 0 ; r < s2.size() ; r++) {
            // add
            mixed[s2[r]]++;

            // if out of bound window
            if(r - l + 1 > windowSize) {
                mixed[s2[l]]--;
                if(mixed[s2[l]] == 0) {
                    mixed.erase(s2[l]);
                }

                l++;
            }

            // reached window size
            if(r - l + 1 == windowSize) {
                // both window have same frequency elements -- Permutation in String found!!
                if(permutationCheck(original, mixed)) {
                    return true;
                }
            }
        }

        return false;

    }
};