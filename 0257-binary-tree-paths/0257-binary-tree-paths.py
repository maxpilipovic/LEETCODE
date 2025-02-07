# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:

        res = []
        curr = []

        def backtrack(node):
            if not node:
                return

            #Add curr node
            curr.append(str(node.val))
            
            #Base case
            #Check left and right if leaf node
            if not node.left and not node.right:
                res.append("->".join(curr))

            #Recursive
            if node.left:
                backtrack(node.left)
            if node.right:
                backtrack(node.right)
            
            curr.pop()

        backtrack(root)
        return res

            



        