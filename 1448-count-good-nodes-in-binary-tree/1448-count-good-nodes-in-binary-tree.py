# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        count = 0
        maxVal = root.val
        stack = [(root, maxVal)]

        while stack:

            node, maxVal = stack.pop()

            if node.val >= maxVal:
                count += 1

            #Update our node.val to compare
            maxVal = max(maxVal, node.val)
            

            if node.right:
                stack.append((node.right, maxVal))
            if node.left:
                stack.append((node.left, maxVal))

        return count