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
    int findMaxDifference(TreeNode* root, int minV, int maxV) {
        // if reach end
        // find max difference in branch
        if(root == nullptr) {
            return abs(maxV - minV);
        }

        minV = min(minV, root->val);
        maxV = max(maxV, root->val);

        int l = findMaxDifference(root->left, minV, maxV);
        int r = findMaxDifference(root->right, minV, maxV);

        return max(l, r);
    }

    int maxAncestorDiff(TreeNode* root) {
        return findMaxDifference(root, root->val, root->val);
    }
};