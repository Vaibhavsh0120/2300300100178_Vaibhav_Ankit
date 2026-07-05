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
    int good = 0;

    void calculate(int maxYet, TreeNode* root) {
        if(root->val >= maxYet) {
            good++;
            maxYet = root->val;
        }

        if(root->left) {
            calculate(maxYet, root->left);
        }

        if(root->right) {
            calculate(maxYet, root->right);
        }

    }
    int goodNodes(TreeNode* root) {
        // we will use inorder technique 
        // if curr value is equal or larger than the largest we have seen yet
        // then its a good node

        calculate(root->val, root);

        return good;
    }
};