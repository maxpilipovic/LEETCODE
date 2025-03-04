# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> List[int]:
        
        res = []

        #Traverse the left tree
        stack = [(root1)]

        while stack:
            node = stack.pop()

            if not node:
                continue

            #Add to list
            res.append(node.val)

            #Check
            if node.left:
                stack.append(node.left)
            
            if node.right:
                stack.append(node.right)

        #Traverse right tree
        stack2 = [(root2)]

        while stack2:
            node = stack2.pop()

            if not node:
                continue

            #Add to list
            res.append(node.val)

            #Check
            if node.left:
                stack2.append(node.left)
            
            if node.right:
                stack2.append(node.right)

        return sorted(res)

