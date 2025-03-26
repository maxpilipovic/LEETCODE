# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """

        if not root:
            return root

        #Dummy value
        dummy = TreeNode(-1)
        self.curr = dummy

        def dfs(node):

            if not node:
                return

            self.curr.right = TreeNode(node.val)
            self.curr = self.curr.right

            dfs(node.left)
            dfs(node.right)
        
        dfs(root)

        #Copy back to og list
        root.left = None
        root.right = dummy.right.right


        