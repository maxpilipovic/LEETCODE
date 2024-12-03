# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:


        stack = [(p, q)]

        while stack:

            val1, val2 = stack.pop()

            if not val1 and not val2:
                continue
            if not val1 or not val2:
                return False
            if val1.val != val2.val:
                return False

            stack.append((val1.left, val2.left))
            stack.append((val1.right, val2.right))

        return True









        