# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        
        if not root:
            return 0

        #Flag -> False - Right? -> Left -> True?
        stack = []
        stack.append((root.left, True, 1))
        stack.append((root.right, False, 1))
        maxLen = 0

        while stack:

            node, direction, count = stack.pop()

            if not node:
                continue
                
            #MaxLength
            maxLen = max(maxLen, count)

            if direction: #True
                stack.append((node.right, False, count + 1))
                stack.append((node.left, True, 1)) #Node.left?
            
            if not direction:
                stack.append((node.left, True, count + 1)) 
                stack.append((node.right, False, 1))

        return maxLen


