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
    bool isBST(TreeNode* root, int left_range, int right_range) {
        if (!root) return true;
        if (!(root -> val > left_range and root -> val < right_range)) {
            return false;
        }
        return isBST(root -> left, left_range, root -> val) and isBST(root -> right, root -> val, right_range);
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return isBST(root -> left, INT_MIN, root -> val) and isBST(root -> right, root -> val, INT_MAX);
    }
};
