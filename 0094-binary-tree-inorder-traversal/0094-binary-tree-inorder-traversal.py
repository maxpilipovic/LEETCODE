# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        res = []

        def dfs(node):
            
            #Base Case
            #If we see null node:
            if not node:
                return
            
            #Recursive Case
            dfs(node.left)
            res.append(node.val)

            #res.append(root.val)

            dfs(node.right)

            


        dfs(root)

        return res
        