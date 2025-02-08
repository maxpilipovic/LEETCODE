# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:

        #Recursive using backtracking

        def backtrack(first, second):
            if not first and not second:
                return True

            #Base case
            if not first or not second:
                return False
            if first.val != second.val:
                return False
            
            #Recursive case
            return backtrack(first.left, second.left) and backtrack(first.right, second.right)

        return backtrack(p, q)



        