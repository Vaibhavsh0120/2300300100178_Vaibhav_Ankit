/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    int checkHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0; // leaf node
        }

        int left = checkHeight(root->left);
        if (left == -1) {   // check if - left side not balanced
            return -1; 
        }

        int right = checkHeight(root->right);
        if (right == -1)    // check if - right side not balanced
            return -1;

        if (abs(left - right) > 1) { // check if - curr is balanced
            return -1; 
        }

        return max(left, right) + 1; // if current balance return maxHeight(left, right)
    }

    bool isBalanced(TreeNode* root) {
         return checkHeight(root) != -1; 
    }
};