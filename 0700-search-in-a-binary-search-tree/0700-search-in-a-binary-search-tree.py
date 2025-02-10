# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:

        def dfs(node):

            #Base
            if not node:
                return None

            #Found it
            if node.val == val:
                return node
            
            #Recursive
            leftResult = dfs(node.left)

            #Check if it exists (Checking if its not none)
            if leftResult:
                return leftResult
            
            return dfs(node.right)
        
        return dfs(root)

        