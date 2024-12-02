# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:

        if not root:
            return 0

        #dfs
        stack = [(root, 1)]
        min_level = float('inf')

        while stack:
            n = len(stack)
            node, level = stack.pop()

            if not node.left and not node.right:
                min_level = min(min_level, level)
                 
            if node.left:
                stack.append((node.left, level + 1))
            if node.right:
                stack.append((node.right, level + 1))
        
        return min_level
                    




        