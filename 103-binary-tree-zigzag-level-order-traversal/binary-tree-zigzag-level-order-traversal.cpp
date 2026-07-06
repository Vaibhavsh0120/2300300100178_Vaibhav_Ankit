/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }

        vector<vector<int>> ans;

        queue<TreeNode*> q;

        int currLevel = 0;

        q.push(root);

        while(!q.empty()) {
            // current level
            currLevel++;

            // no of element in curr level
            int currLevelSize = q.size();

            // curr level elements
            vector<int> currLevelElt;

            for(int i = 0 ; i < currLevelSize ; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left != nullptr) {
                    q.push(node->left);
                }

                if(node->right != nullptr) {
                    q.push(node->right);
                }

                currLevelElt.push_back(node->val);
            }

            if(currLevel % 2 == 0) {
                reverse(currLevelElt.begin(), currLevelElt.end());
            }

            ans.push_back(currLevelElt);
        }

        return ans;
    }
};