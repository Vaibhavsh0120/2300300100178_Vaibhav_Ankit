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
    void swapper(TreeNode* left, TreeNode* right, int level) {
        if(left == nullptr || right == nullptr) {
            return;
        }

        if(level % 2 != 0) {
            swap(left->val, right->val);
        }

        swapper(left->right, right->left, level + 1);
        swapper(left->left, right->right, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == nullptr) {
            return root;
        }

        swapper(root->left, root->right, 1);

        return root;
    }
};