# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        #Start at leftmost node

        res = []

        def dfs(node):

            if not node:
                return

            if not node.left and not node.right:
                #Append the child
                res.append(node.val)
                return
            
            #Left node
            dfs(node.left)
            
            #Append current node
            res.append(node.val)
            
            #Right node
            dfs(node.right)

        dfs(root)

        return res


        