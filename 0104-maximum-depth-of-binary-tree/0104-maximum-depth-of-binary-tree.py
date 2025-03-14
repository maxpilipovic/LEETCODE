# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:


        def dfs(node):
            
            #Base Case
            if not node:
                return 0
            
            #Recursive
            leftDepth = dfs(node.left)
            rightDepth = dfs(node.right)
            
            return max(leftDepth, rightDepth) + 1

        return dfs(root)


        