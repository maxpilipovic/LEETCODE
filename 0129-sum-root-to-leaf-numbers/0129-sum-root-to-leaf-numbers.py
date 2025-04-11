# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        
        res = []
        stack = [([root, ""])]

        while stack:
            node, currPath = stack.pop()

            currPath += str(node.val)

            if not node.left and not node.right:
                res.append(int(currPath))
            
            if node.left:
                stack.append((node.left, currPath))
            if node.right:
                stack.append((node.right, currPath))
        
        return sum(num for num in res)

        