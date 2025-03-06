# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:

        current = root
        prev = None
        stack = []
        minDiff = float('inf')

        while stack or current:
            
            #We have to get to the leftmost node
            while current:
                stack.append(current)
                current = current.left

            #Process node
            node = stack.pop()

            if prev is not None:
                minDiff = min(minDiff, node.val - prev.val)

            prev = node
            
            current = node.right

        return minDiff


        