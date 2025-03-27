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

        queue = deque([root])
        res = []
        count = 0

        while queue:
            
            curr = []
            length = len(queue)

            for i in range(length):

                node = queue.popleft()

                #Add to curr
                curr.append(node.val)

                if i == length - 1:

                    #If our level is odd
                    if count % 2 != 0:
                        curr.reverse()
                    
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                
            res.append(curr)
            count += 1
        
        return res
            




