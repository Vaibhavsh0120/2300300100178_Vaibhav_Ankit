class Solution {
public:
    int strStr(string haystack, string needle) {

        int i = 0;
        int j = needle.size();

        while(j <= haystack.size()) {

            // check the window to haystack
            int hay_ptr = i;
            int needle_ptr = 0;
            while(hay_ptr <= j) {
                // match complete
                if(hay_ptr == j) {
                    return i;
                }
                // not match
                if(haystack[hay_ptr] != needle[needle_ptr]) {
                    break;
                }
                hay_ptr++;
                needle_ptr++;
            }

            // move window
            i++;
            j++;
        }

        return -1;
    }
};