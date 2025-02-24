# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        
        res = []

        def dfs(node, curr):
            if not node:
                return
            
            #Make our ASCII calculation
            curr = chr(ord('a') + node.val) + curr

            #If its a leaf node
            if not node.right and not node.left:
                res.append(curr)
                return 

            #Recursive Case
            if node.left:
                dfs(node.left, curr)
            if node.right:
                dfs(node.right, curr)
        
        dfs(root, "")

        return min(res)
        