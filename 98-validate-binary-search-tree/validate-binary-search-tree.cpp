/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Checks whether every node lies in the range (leftMax, rightMax)
    bool checkBST(TreeNode* root, long long leftMax, long long rightMax) {
        // Empty tree is always a valid BST
        if (root == nullptr) {
            return true;
        }

        // Current node must satisfy:
        // leftMax < root->val < rightMax
        if (root->val <= leftMax || root->val >= rightMax) {
            return false;
        }

        // Left subtree:
        // Values must be in (leftMax, root->val)
        bool left = checkBST(root->left, leftMax, root->val);

        // Right subtree:
        // Values must be in (root->val, rightMax)
        bool right = checkBST(root->right, root->val, rightMax);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        // Initially, every integer value is allowed
        return checkBST(root, LLONG_MIN, LLONG_MAX);
    }
};