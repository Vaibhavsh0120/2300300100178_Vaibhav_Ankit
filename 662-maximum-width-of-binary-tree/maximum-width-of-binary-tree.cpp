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
    int widthOfBinaryTree(TreeNode* root) {
        // Maximum Width of Complete Binary Tree
        // Using BST - 102
        // Using (Complete Binary Tree) CBT Index

        // root -> i
        // left -> 2*i + 1
        // right -> 2*i + 2

        // eg [1,3,2,5,3, ,9]

        // width = index of last elt of level - index of first elt of level + 1

        // node, currIndex
        queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});

        unsigned long long maxWidth = 0;

        while(q.size() > 0) {
            int currLevelSize = q.size();

            unsigned long long startIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxWidth = max(maxWidth, endIdx - startIdx + 1);

            for(int i = 0 ; i < currLevelSize ; i++) {
                TreeNode* node = q.front().first;
                unsigned long long idx = q.front().second - startIdx;   // normalize

                q.pop();

                if(node->left != nullptr) {
                    q.push({node->left, idx*2 + 1});
                }

                if(node->right != nullptr) {
                    q.push({node->right, idx*2 + 2});
                }
            }
        }

        return maxWidth;
    }
};