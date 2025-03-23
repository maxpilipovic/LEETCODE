# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        
        if not root:
            return 0
        queue = deque([(root, 1)])
        maxDepth = 0

        while queue:
            length = len(queue)
            for i in range(length):
                node, depth = queue.popleft()
                
                maxDepth = max(maxDepth, depth)

                if node.left:
                    queue.append((node.left, depth + 1))
                if node.right:
                    queue.append((node.right, depth + 1))

        
        return depth