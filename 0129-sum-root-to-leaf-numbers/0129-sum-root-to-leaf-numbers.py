# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        res = []

        def dfs(node, curr):
            if not root:
                return

            #Build our string per node.val
            curr += str(node.val)

            #If leaf node
            if not node.left and not node.right:
                res.append(int(curr))
                return
            
            #Recursive
            if node.left:
                dfs(node.left, curr)
            if node.right:
                dfs(node.right, curr) 

        dfs(root, "")
        
        return sum(res)



        