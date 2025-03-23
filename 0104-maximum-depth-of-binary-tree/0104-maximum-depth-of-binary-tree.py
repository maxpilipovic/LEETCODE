# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        
        maxDepth = 0

        def dfs(node, depth):
            nonlocal maxDepth
            
            if not node:
                return
            
            maxDepth = max(maxDepth, depth)

            if node.left:
                node.left = dfs(node.left, depth + 1)

            if node.right:
                node.right = dfs(node.right, depth + 1)

        dfs(root, 1)

        return maxDepth



        