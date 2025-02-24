# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        
        res = []
        stack = [(root, "")]

        while stack:

            node, curr = stack.pop()

            #Check if null
            if not node:
                continue

            curr = chr(ord('a') + node.val) + curr

            #Is it a leaf
            if not node.left and not node.right:
                res.append(curr)
                continue
            
            #Check left and right node
            if node.left:
                stack.append((node.left, curr))
            if node.right:
                stack.append((node.right, curr))

        return min(res)