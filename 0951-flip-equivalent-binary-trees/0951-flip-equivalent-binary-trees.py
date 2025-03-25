# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:

        if not root1 and not root2:
            return True

        def dfs(node1, node2):

            if not node1 and not node2:
                return True

            if not node1 or not node2:
                return False
            
            if node1.val != node2.val:
                return False

            leftRes = dfs(node1.left, node2.right)
            if leftRes:
                return leftRes
            
            rightRes = dfs(node1.right, node2.left)
            if rightRes:
                return rightRes
            
            return False

        
        return dfs(root1, root2)


        