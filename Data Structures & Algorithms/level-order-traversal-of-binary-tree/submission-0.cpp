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

        // Edge case, if the root doesn't exist, we return empty vector.
        if (!root) {
            return result;
        }

        // Else we do a BFS with a queue data structure.
        // Since it's a tree, it's not going to contain cycles, so we can avoid the visited
        // information.
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // process each level by level.
            vector<int> nodes_at_level;
            const int q_size = q.size();
            // pop these many elements.
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
