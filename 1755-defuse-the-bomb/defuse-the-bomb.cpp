class Solution {
public:
    vector<int> forwardSum(vector<int>& code, int k) {
        vector<int> ans(code.size(), 0);

        for(int p = 0 ; p < code.size() ; p++) {
            
            int curSum = 0;
            int index = p + 1;

            for(int i = 0 ; i < k ; i++) {
                curSum += code[index % code.size()];
                index++;
            }

            ans[p] = curSum;
        }

        return ans;
    }

    vector<int> previousSum(vector<int>& code, int k) {
        vector<int> ans(code.size(), 0);

        for(int p = 0 ; p < code.size() ; p++) {
            
            int curSum = 0;
            int index = p - 1;

            for(int i = 0 ; i < k ; i++) {
                curSum += code[(index + code.size()) % code.size()];
                index--;
            }

            ans[p] = curSum;
        }

        return ans;
    }

    vector<int> decrypt(vector<int>& code, int k) {

        if(k == 0) {
            return vector<int>(code.size(), 0);
        }
        else if(0 < k) {
            return forwardSum(code, k);
        }
        else {
            return previousSum(code, -k);
        }
    }
};