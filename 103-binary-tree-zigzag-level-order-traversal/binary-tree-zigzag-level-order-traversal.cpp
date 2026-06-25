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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int levelCount = 0;
        vector<vector<int>> soln;

        if (root == nullptr) {
            return soln;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            levelCount++;
            int sizeOfLevel = q.size();
            vector<int> currLevel;

            for (int i = 0; i < sizeOfLevel; i++) {
                TreeNode* curr = q.front();
                q.pop();

                currLevel.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            // CHANGE DIRECTION (ELSE EXACT SAME AS 102)
            if(levelCount % 2 != 0) {
                soln.push_back(currLevel);
            }
            else {
                reverse(currLevel.begin(), currLevel.end());
                soln.push_back(currLevel);
            }
        }

        return soln;
    }
};