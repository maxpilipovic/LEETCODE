# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        
        queue = deque([root])
        res = []

        while queue:

            length = len(queue)
            for i in range(length):
                node = queue.popleft()

                if node.val >= low and node.val <= high:
                    res.append(node.val)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        

        #Add each
        ans = sum(res)

        return ans
