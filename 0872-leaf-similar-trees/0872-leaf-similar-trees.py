# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:

        res1 = []
        res2 = []

        def dfs(node, array):
            if not node:
                return


            if not node.left and not node.right:
                array.append(node.val)

            node.left = dfs(node.left, array)
            node.right = dfs(node.right, array)


        dfs(root1, res1)
        dfs(root2, res2)

        return True if res1 == res2 else False
        