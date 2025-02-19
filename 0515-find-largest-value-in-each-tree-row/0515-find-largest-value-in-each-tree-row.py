# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque 
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        
        if not root:
            return []
        queue = deque([root])
        res = []

        while queue:
            lengthSize = len(queue)
            largeVal = float('-inf')
            for i in range(lengthSize):
                node = queue.popleft()

                if node.val > largeVal:
                    largeVal = node.val
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            res.append(largeVal)
        
        return res



        