# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:

        queue = deque([root])

        while queue:
            length = len(queue)
            xFlag = False
            yFlag = False

            for _ in range(length):

                node = queue.popleft()

                #Check node is None
                if not node:
                    continue

                #Check flags
                if node.val == x:
                    xFlag = True
                if node.val == y:
                    yFlag = True

                #Check if x and y are siblings
                if node.left and node.right:
                    if (node.left.val == x and node.right.val == y) or (node.left.val == y and node.right.val == x):
                        return False

                #Add children
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            if xFlag and yFlag:
                return True
        
        return False
 




        