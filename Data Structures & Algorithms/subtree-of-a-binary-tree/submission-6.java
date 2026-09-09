/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    private boolean isSame(TreeNode p1, TreeNode p2) {
        // 1. if both are null, that means the tree are equals.
        if (p1 == null && p2 == null) {
            return true;
        }

        // 2. If either of the nodes is present, or if the values are different.
        // Then the trees are not equals, and do a return of True.
        if (p1 == null || p2 == null || p1.val != p2.val) {
            return false;
        }

        // 3. If all passes, we compare the left subtree and the right subtree as well.
        // Since till now the equality is for the Treenodes.
        return isSame(p1.left, p2.left) && isSame(p1.right, p2.right);
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null) {
            return false;
        }
        if (subRoot == null) {
            return true;
        }
        if (isSame(root, subRoot)) return true;
        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }
}
