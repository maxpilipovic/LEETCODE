# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution(object):
    def minDepth(self, root):
        
        if not root:
            return 0

        q = deque()
        q.append(root)

        level = 1
        while q:
            n = len(q)

            for _ in range(n):
                node = q.popleft()

                if not node.left and not node.right:
                    return level

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            level += 1
        
        return level

        
        
        