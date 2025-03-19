# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: Optional[TreeNode], distance: int) -> int:
        
        total = 0

        def dfs(node):
            
            if not node.left and not node.right:
                return [1]
            
            descendants = []
            nonlocal total

            left = dfs(node.left) if node.left else []
            right = dfs(node.right) if node.right else []

            for i in left:
                if i >= distance: #If greater in left,  no need to check right subtree
                    continue
                
                for j in right:
                    if i + j <= distance:
                        total += 1
            
            return [i + 1 for i in left + right]

        dfs(root)

        return total

            


        

        dfs(root)