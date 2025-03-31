# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        res = 0

        def dfs(node, p, q):
            #Base Case
            if not node:
                return None

            #Base Case
            if node == p or node == q:
                return node

            #Check left and right childen first
            left = dfs(node.left, p, q)
            right = dfs(node.right, p, q)

            if left and right:
                return node
            
            return left if left else right

        return dfs(root, p, q)



        
            

            
