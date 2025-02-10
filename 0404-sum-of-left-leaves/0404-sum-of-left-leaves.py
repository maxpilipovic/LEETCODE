# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            #Base case
            if not node:
                return 0

            sumLeft = 0
        
            #Recursive | Checking node.left and a leaf (node.left.left) (node.left.right)
            if node.left and not node.left.left and not node.left.right:
                sumLeft += node.left.val
            
            return sumLeft + dfs(node.left) + dfs(node.right)
        
        return dfs(root)

        