# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        #BFS
        if root is None:
            return None

        q = deque([root])
        level = 0

        while q:
            #check nodes at level
            size = len(q)
            if level % 2 == 1:
                #get everything in q
                values = [node.val for node in q]

                #swap
                values.reverse()

                #add them back to q reversed
                for i, node in enumerate(q):
                    node.val = values[i]

            for _ in range(size):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                    
            level += 1
            
        return root