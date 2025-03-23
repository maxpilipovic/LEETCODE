# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        
        if not root:
            return False

        stack = [(root, 0)]

        while stack:

            node, currSum = stack.pop()

            #Add the curr sum
            currSum += node.val

            if currSum == targetSum and not node.left and not node.right:
                return True

            if node.left:
                stack.append((node.left, currSum))
            if node.right:
                stack.append((node.right, currSum))

        return False
        