# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSameTree(self, p, q):

        if p is None and q is None:
            return True
        
        while p.left == p.right:

            if (p.left != p.right):
                return False
            self.isSameTree(p.left, p.right)
        return True




        