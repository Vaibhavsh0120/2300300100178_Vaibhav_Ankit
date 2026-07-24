class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> mapST;
        unordered_map<int, int> mapTS;

        for(int i = 0 ; i < s.size() ; i++) {

            // check if we have seen char in s
            if(mapST.count(s[i])) {
                // if we have already seen s[i] and it is mapped with diffent char
                if(mapST[s[i]] != t[i]) {
                    return false;
                }
            }
            // seeing char first time
            else {
                mapST[s[i]] = t[i];
            }

            if(mapTS.count(t[i])) {
                if(mapTS[t[i]] != s[i]) {
                    return false;
                }
            }
            else {
                mapTS[t[i]] = s[i];
            }
        }

        return true;
    }
};