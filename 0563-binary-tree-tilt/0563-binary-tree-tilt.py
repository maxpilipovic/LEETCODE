# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        self.totalTilt = 0

        def dfs(node):
            
            #Base Case
            if not node:
                return 0
            
            leftSum = dfs(node.left)
            rightSum = dfs(node.right)

            
            nodeTilt = abs(leftSum - rightSum)
            self.totalTilt += nodeTilt

            return node.val + leftSum + rightSum
        
        dfs(root)
        return self.totalTilt


        