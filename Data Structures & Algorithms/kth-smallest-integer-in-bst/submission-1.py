# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def _dfs(self, node: Optional[TreeNode], k: int):
        if node:
            self._dfs(node.left, k)
            # process the node.
            self.node_number += 1
            if self.node_number == k:
                self.answer = node.val
            self._dfs(node.right, k)
        
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.answer = -1
        self.node_number = 0
        self._dfs(root, k)
        return self.answer

