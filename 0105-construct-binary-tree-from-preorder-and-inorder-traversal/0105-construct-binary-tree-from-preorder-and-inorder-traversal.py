# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        
        #Base Case
        if not preorder and not inorder:
            return None
        
        root = TreeNode(preorder[0])

        #Index our root in inorder
        mid = inorder.index(preorder[0])

        #Recursive
        root.left = self.buildTree(preorder[1: mid + 1], inorder[:mid]) #Left
        root.right = self.buildTree(preorder[mid+1:], inorder[mid + 1:]) #Right

        return root
           
