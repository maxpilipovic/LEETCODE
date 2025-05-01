# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        if not root:
            return 0

        res = 1

        def dfs(node, currMax):
            nonlocal res

            #Base Case
            if not node:
                return

            if node.val >= currMax:
                res += 1
                currMax = node.val

            #Recursive
            if node.left:
                dfs(node.left, currMax)
            if node.right:
                dfs(node.right, currMax)
        
        dfs(root.left, root.val)
        dfs(root.right, root.val)

        return res