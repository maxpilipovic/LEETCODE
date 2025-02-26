# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        count = 0
        
        def dfs(node, maxVal, count):
            #Base
            if not node:
                return count
            
            #Check
            if node.val >= maxVal:
                count += 1

            #Update our node.val to compare
            maxVal = max(maxVal, node.val)
            
            #Recursive
            count = dfs(node.left, maxVal, count)
            count = dfs(node.right, maxVal, count)

            return count
        
        return dfs(root, root.val, count)