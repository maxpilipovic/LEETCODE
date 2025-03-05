# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        maxWidth = 0
        queue = deque([(root, 0)])

        while queue:
            length = len(queue)

            #Track indexes
            _, firstIndex = queue[0]
            _, lastIndex = queue[-1]
            maxWidth = max(maxWidth, lastIndex - firstIndex + 1)

            for i in range(length):
                node, index = queue.popleft()

                if node.left:
                    queue.append((node.left, 2 * index))
                
                if node.right:
                    queue.append((node.right, 2 * index + 1))

        return maxWidth