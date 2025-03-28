# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:

        stack = [(root, 0, 0), (root, 1, 0)]
        res = 0

        while stack:

            node, direction, length = stack.pop()
            
            #Check our max zig zag
            res = max(res, length)

            if node.left:
                if direction == 0: #Come for left
                    stack.append((node.left, 0, 1))
                else: #Come from right
                    stack.append((node.left, 0, length + 1))
            if node.right:
                if direction == 1: #Come from right
                    stack.append((node.right, 1, 1))

                else: #Come from left
                    stack.append((node.right, 1, length + 1))
        
        return res

            
            

            
        