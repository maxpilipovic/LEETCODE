# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        res = []

        def inOrderTraversal(node):
            
            #Base Case
            if not node:
                return

            inOrderTraversal(node.left)
            
            res.append(node.val)

            inOrderTraversal(node.right)

        inOrderTraversal(root)
        print(res)
        for i in range(len(res) - 1):
            if res[i] >= res[i+1]:
                return False

        return True        