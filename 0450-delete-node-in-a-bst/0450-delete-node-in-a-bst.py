# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return root

        def recursion(node, key):

            if not node:
                return node

            if key < node.val:
                node.left = recursion(node.left, key)
            elif key > node.val:
                node.right = recursion(node.right, key)
            else:

                #Case 1 - Node is a leaf
                if not node.left and not node.right:
                    return None

                #Case 2 - Node has one child
                if not node.left or not node.right:
                    return node.left if node.left else node.right

                #Case 3 - Node has two children
                temp = node.left

                while temp.right:
                    temp = temp.right
                
                node.val = temp.val
                node.left = recursion(node.left, temp.val)

            return node
        
        return recursion(root, key)


        