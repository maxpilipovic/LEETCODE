# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        if not root:
            return 0

        stack = [(root, root.val)]
        goodNodes = 0

        while stack:

            node, maxNode = stack.pop()

            if node.val >= maxNode:
                goodNodes += 1
            
            maxNode = max(maxNode, node.val)
            
            if node.left:
                stack.append((node.left, maxNode))
            if node.right:
                stack.append((node.right, maxNode))
        
        return goodNodes

            


        