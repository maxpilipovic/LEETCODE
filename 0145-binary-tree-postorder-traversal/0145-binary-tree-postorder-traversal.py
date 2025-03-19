# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        if not root:
            return []

        res = []

        def dfs(node):

            if not node:
                return None
            
            if node.left:
                node.left = dfs(node.left)
            if node.right:
                node.right = dfs(node.right)

            res.append(node.val)
        
        dfs(root)
        return res