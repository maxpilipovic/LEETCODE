# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:

        res = []
        curr = []

        def dfs(node, curr):
            
            if not node:
                return

            curr.append(node.val)

            if not node.left and not node.right:
                res.append(curr.copy())
            else:

                if node.left:
                    dfs(node.left, curr)
                if node.right:
                    dfs(node.right, curr)

            curr.pop()

        dfs(root, curr)

        result = 0
        for i in res:
            decimalVal = int("".join(map(str, i)), 2)
            result += decimalVal
        
        return result
        
