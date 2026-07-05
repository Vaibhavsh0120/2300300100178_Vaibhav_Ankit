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
    pair<int, int> dfs(TreeNode* root) {
        if(root == nullptr) {
            return {0, 0};
                // with , without
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // if taken root, dont rob next
        int withRoot = root->val + left.second + right.second;

        int withoutRoot = max(left.first, left.second) +
                            max(right.first, right.second);

        return {withRoot, withoutRoot};
    }

    int rob(TreeNode* root) {
        // Depth First Search Soln
        pair<int, int> it = dfs(root);
        return max(it.first, it.second);
                // withRoot , withoutRoot
    }
};