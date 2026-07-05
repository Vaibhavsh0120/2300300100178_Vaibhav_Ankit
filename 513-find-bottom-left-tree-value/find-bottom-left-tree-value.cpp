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
    int findBottomLeftValue(TreeNode* root) {
        // BFS - Right to left (last node is answer) 
        // 102 similar

        queue<TreeNode*> q;

        q.push(root);
        TreeNode* curr = nullptr;

        while(!q.empty()) {
            curr = q.front();
            q.pop();

            if(curr->right) {
                q.push(curr->right);
            }

            if(curr->left) {
                q.push(curr->left);
            }
        }

        return curr->val;
    }
};