# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def sumEvenGrandparent(self, root: Optional[TreeNode]) -> int:

        if not root:
            return 0

        queue = deque([(root, None, None)])
        res = 0

        while queue:

            length = len(queue)

            for i in range(length):
                node, parent, grandparent = queue.popleft()


                #Check grandparent is even
                if grandparent and grandparent.val % 2 == 0:
                    res += node.val

                if node.left:
                    queue.append((node.left, node, parent))
                
                if node.right:
                    queue.append((node.right, node, parent))
            
        return res


        