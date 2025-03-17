# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        
        if not root:
            return 0

        queue = deque([root])
        res = []
        level = 0

        while queue:
            length = len(queue)
            currSum = 0
            level += 1

            for i in range(length):

                node = queue.popleft()

                #Add up sum
                currSum += node.val

                if i == length - 1:
                    #Append to our res
                    res.append([currSum, level])

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                
        #Find our max and return second val in tuple/list
        maxVal = max(res, key=lambda x: x[0])
        
        return maxVal[1]

