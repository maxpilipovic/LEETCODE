# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        


        def dfs(root, array):
            if not root:
                return
            
            if not root.left and not root.right:
                array.append(root.val)
            
            dfs(root.left, array)
            dfs(root.right, array)
        
        array1 = []
        array2 = []

        dfs(root1, array1)
        dfs(root2, array2)

        return array1 == array2



        array1 = []
        array2 = []

            



        