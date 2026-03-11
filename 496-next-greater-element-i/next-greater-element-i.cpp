class Solution {
public:
    vector<int> nextGreaterElement_Hash_Map(vector<int>& nums1, vector<int>& nums2) {

        // for (int &i : nums1) {

        //     auto it = find(nums2.begin(), nums2.end(), i);
        //     int nextGreat = -1;

        //     for (auto j = it + 1; j != nums2.end(); j++) {
        //         if (*j > i) {
        //             nextGreat = *j;
        //             break;
        //         }
        //     }

        //     i = nextGreat;
        // }

        // return nums1;

        // OPTIMAL SOLUTION -------------------

        unordered_map<int, int> mp;
        // value, next greater

        for(int i = 0 ; i < nums2.size() ; i++){

            int nextGreater = -1;

            for(int j = i + 1 ; j < nums2.size() ; j++) {
                if(nums2[i] < nums2[j]) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            mp[nums2[i]] = nextGreater;

        }

        for(int &i : nums1) {
            i = mp[i];
        }

        return nums1;
    }

    // ------------------------------------------------------------------------------

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> nge(nums2.size());
        stack<int> stk;

        for(int i = nums2.size() - 1 ; i >= 0 ; i--) {
            while(!stk.empty() && stk.top() <= nums2[i]) {
                stk.pop();
            }

            nge[i] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }

        vector<int> soln(nums1.size());

        for(int i = 0 ; i < nums1.size() ; i++) {

            int index = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            soln[i] = nge[index];

        }

        return soln;
    }
};