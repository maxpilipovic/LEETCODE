# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:

        stack = [(p, q)]

        #While stack is not empty
        while stack:
            first, second = stack.pop()

            #If both empty
            if not first and not second:
                continue

            #If one is empty and the other is not
            if not first or not second:
                return False

            if first.val != second.val:
                return False
            
            stack.append((first.left, second.left))
            stack.append((first.right, second.right))

        return True
            








        