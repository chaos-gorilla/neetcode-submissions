# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isEqualSubtree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p and q:
            if p.val != q.val:
                return False
            return self.isEqualSubtree(p.left, q.left) and self.isEqualSubtree(p.right, q.right)
        if (p and not q) or (q and not p):
            return False
        return True
        
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        return self.isEqualSubtree(p, q)
        