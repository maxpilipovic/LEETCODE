# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        def dfs(node, depth):

            if not node:
                return (depth, None)

            
            leftDepth, left_lca = dfs(node.left, depth + 1)
            rightDepth, right_lca = dfs(node.right, depth + 1)
            
            if leftDepth == rightDepth:
                return (leftDepth, node)
            
            if leftDepth > rightDepth:
                return (leftDepth, left_lca)
            
            if rightDepth > leftDepth:
                return (rightDepth, right_lca)
            
        
        _, lca = dfs(root, 0)
        return lca