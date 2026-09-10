# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self) -> None:
        self.k = float("infinity")
    
    def _dfs(self, node: Optional[TreeNode], nodes: list):
        if node:
            self._dfs(node.left, nodes)
            nodes.append(node)
            self._dfs(node.right, nodes)
        
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        nodes = []
        self._dfs(root, nodes=nodes)
        return nodes[k - 1].val

