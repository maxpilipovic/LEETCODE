# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        
        #Check if root is empty
        if not root:
            return []

        res = []
        stack = [(root, str(root.val))]

        while stack:
            node, path = stack.pop()
            
            #If its a leaf
            if not node.left and not node.right:
                res.append(path)
            
            if node.right:
                stack.append((node.right, path + "->" +str(node.right.val)))
            if node.left:
                stack.append((node.left, path + "->" + str(node.left.val)))
        
        return res


            



        