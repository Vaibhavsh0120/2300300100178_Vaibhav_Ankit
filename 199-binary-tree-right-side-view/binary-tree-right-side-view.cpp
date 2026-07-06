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
    vector<int> ans;

    void ReversePreOrderTraversal(TreeNode* root, int level) {
        // normal   -> Root Left Right
        // Reverse - > Root [Right] Left

        if(root == nullptr) {
            return;
        }

        // if we are seeing first ever element of this level
        // ans will store 1 element pre level
        if(level > ans.size()) {
            ans.push_back(root->val);
        }

        ReversePreOrderTraversal(root->right, level + 1);
        ReversePreOrderTraversal(root->left, level + 1);

    }

    vector<int> rightSideView(TreeNode* root) {
        // Using every first element of reverse Pre Order traversal

        ReversePreOrderTraversal(root, 1);

        return ans;

    }
};