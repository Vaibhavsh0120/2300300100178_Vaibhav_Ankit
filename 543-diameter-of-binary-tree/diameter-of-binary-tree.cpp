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
    //global
    int diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        Height(root);

        return diameter;
    }

    // return max height from left or right
    int Height(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }

        int maxLeftHeight = Height(root->left);
        int maxRighttHeight = Height(root->right);

        // calculate diameter
        diameter = max(diameter, maxLeftHeight + maxRighttHeight);

        // return max height between left and right

        return max(maxLeftHeight, maxRighttHeight) + 1;
    }
};