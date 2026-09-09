class Solution {
    private boolean isSame(TreeNode p1, TreeNode p2) {
        if (p1 == null && p2 == null) return true;
        if (p1 == null || p2 == null || p1.val != p2.val) return false;
        return isSame(p1.left, p2.left) && isSame(p1.right, p2.right);
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null) return false;
        if (subRoot == null) return true;
        if (isSame(root, subRoot)) return true;
        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }
}
