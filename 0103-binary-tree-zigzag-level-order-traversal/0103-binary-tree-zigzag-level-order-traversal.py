# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        if not root:
            return []
            
        res = []
        queue = deque([(root, 0)])

        while queue:

            length = len(queue)
            curr = []

            for i in range(length):

                node, level = queue.popleft()
                curr.append(node.val)

                #We know this is the last value
                if length - 1 == i:
                    if level % 2 == 0:
                        #Even
                        res.append(curr.copy())
                    else:
                        #Odd
                        curr.reverse()
                        res.append(curr.copy())
                
                if node.left:
                    queue.append((node.left, level + 1))
                if node.right:
                    queue.append((node.right, level + 1))
        
        return res