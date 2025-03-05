# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:

        sortedArray = []
        stack = []
        current = root

        while current or stack:

            while current:
                stack.append(current)
                current = current.left
            
            current = stack.pop()
            sortedArray.append(current.val)
            current = current.right
        
        diff = float('inf')
        for i in range(1, len(sortedArray)):
            diff = min(diff, sortedArray[i]- sortedArray[i-1])
        
        return diff