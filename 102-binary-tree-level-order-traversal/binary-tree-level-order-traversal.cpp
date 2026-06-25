class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> soln;

        if (root == nullptr) {
            return soln;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
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

            soln.push_back(currLevel);
        }

        return soln;
    }
};