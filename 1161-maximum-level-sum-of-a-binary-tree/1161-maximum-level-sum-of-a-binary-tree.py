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
        level = 0
        maxSum = float('-inf')
        maxLevel = 1


        while queue:
            length = len(queue)
            level += 1
            levelSum = 0

            for i in range(length):
                node = queue.popleft()

                #Append max val
                levelSum += node.val

                #We at last val, so add key = level, value = maxVal
                if i == length - 1:
                    if levelSum > maxSum:
                        maxLevel = level
                    maxSum = max(maxSum, levelSum)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        
        return maxLevel
                

