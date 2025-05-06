# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        
        if not root:
            return 0
            
        def dfs(node, curr):

            if not node:
                return 0

            curr += node.val
            
            count = 1 if curr == targetSum else 0
            
            count += dfs(node.left, curr)
            count += dfs(node.right, curr) 

            return count   

        count = 0
        queue = deque()
        queue.append(root)
        while queue:

            length = len(queue)

            for _ in range(length):
                
                node = queue.popleft()

                #Do something
                count += dfs(node, 0)

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

        
        return count
        
