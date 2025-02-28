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

        res = []
        queue = deque([root])

        while queue:
            length = len(queue)
            curr = []

            for i in range(length):
                node = queue.popleft()

                curr.append(node.val)

                #Check children
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            print(curr)
            res.append(curr)
        
        return res








        