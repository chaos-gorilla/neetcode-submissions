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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> nodes_at_level;
            const int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode* front = q.front();
                q.pop();
                nodes_at_level.push_back(front -> val);
                if (front -> left) q.push(front -> left);
                if (front -> right) q.push(front -> right);
            }
            result.push_back(nodes_at_level);
        }

        return result;
    }
};
