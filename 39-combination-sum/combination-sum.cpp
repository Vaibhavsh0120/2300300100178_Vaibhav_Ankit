#include <vector>
using namespace std;

class Solution {
public:

    void solve(int i, vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& ans)
    {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (i == candidates.size()) return;

        if (target >= candidates[i]) {
            curr.push_back(candidates[i]);

            solve(i, candidates, target - candidates[i], curr, ans);

            curr.pop_back();   // backtrack
        }

        solve(i + 1, candidates, target, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, candidates, target, curr, ans);

        return ans;
    }
};