# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:

        def dfs(node, depth, maxDepth, leftValue):
            #Base Case | Returning empty value
            if not node:
                return maxDepth, leftValue
            
            if depth > maxDepth:
                maxDepth = depth
                leftValue = node.val

            #Recursive 
            maxDepth, leftValue = dfs(node.left, depth + 1, maxDepth, leftValue)
            maxDepth, leftValue = dfs(node.right, depth + 1, maxDepth, leftValue)
        
            return maxDepth, leftValue

        maxDepth = -1
        leftValue = 0


        maxDepth, leftValue = dfs(root, 0, maxDepth, leftValue)

        return leftValue
        