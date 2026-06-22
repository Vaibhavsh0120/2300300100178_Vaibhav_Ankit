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
    void helper(TreeNode* root, vector<int>& soln) {
        if(root == nullptr) {
            return;
        }

        helper(root->left, soln);

        helper(root->right, soln);

        soln.push_back(root->val);

        return;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> soln;

        helper(root, soln);

        return soln;
    }
};