# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        if not root:
            return []

        queue = deque()
        queue.append(root)
        res = []


        #FIFO

        #First iteration of queue
        #CURR = [1]
        #Second itetation of queue
        #CURR = [9, 20]
        #Third iteration of queue
        #CURR = [15, 7]
        while queue:

            length = len(queue)
            curr = [] #Curr goes back to being empty

            for _ in range(length):

                node = queue.popleft()
                curr.append(node.val)

                #Check our left and right node
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            res.append(curr)
        
        return res




        

