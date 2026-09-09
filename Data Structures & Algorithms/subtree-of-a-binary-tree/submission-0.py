# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSame(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        if not p or not q or p.val != q.val:
            return False
        return self.isSame(p.left, q.left) and self.isSame(p.right, q.right)

    def dfs(self, node: Optional[TreeNode], value_finding: int, nodes_list: list[TreeNode]):
        if not node:
            return 
        if node.val == value_finding:
            nodes_list.append(node)
        self.dfs(node.left, value_finding, nodes_list)
        self.dfs(node.right, value_finding, nodes_list)


    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        list_of_nodes = []
        self.dfs(root, subRoot.val, list_of_nodes)

        for node in list_of_nodes:
            if self.isSame(node, subRoot):
                return True
        
        return False
