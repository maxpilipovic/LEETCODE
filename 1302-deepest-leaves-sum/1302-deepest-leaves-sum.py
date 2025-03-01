# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:

        if not root:
            return 0
        
        #BFS
        queue = deque([root])
        res = 0

        while queue:

            length = len(queue)
            res = 0

            for i in range(length):
                node = queue.popleft()

                #Check if its a child with no children (deepest)
                if not node.left and not node.right:
                    res += node.val
                    print(node.val)

                #Check left then right
                if node.left:
                    queue.append(node.left)
                
                if node.right:
                    queue.append(node.right)
                
        return res


                
            

        