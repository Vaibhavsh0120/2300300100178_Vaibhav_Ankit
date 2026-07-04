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
    void swapBranch(TreeNode* left, TreeNode* right, int level) {
        // base case
        if(left == nullptr || right == nullptr) {
            return;
        }


        // swap if odd level
        if(level % 2 != 0) {
            swap(left->val, right->val);
        }

        swapBranch(left->left, right->right, level + 1);
        swapBranch(left->right, right->left, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == nullptr) {
            return root;
        }

        swapBranch(root->left, root->right, 1);
        return root;
    }
};