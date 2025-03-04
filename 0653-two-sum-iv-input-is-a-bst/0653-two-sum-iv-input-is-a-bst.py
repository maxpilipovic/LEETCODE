# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:

        if not root:
            return False

        hashy = set()

        stack = [(root)]

        while stack:

            node = stack.pop()

            #Check ifempty
            if not node:
                continue

            #Check if hashy has a seen the value before
            if k - node.val in hashy:
                return True

            #Add to our hashy
            hashy.add(node.val)
            
            if node.left:
                stack.append(node.left)
            
            if node.right:
                stack.append(node.right)
            
        return False
        