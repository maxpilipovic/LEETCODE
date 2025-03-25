# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        
        if not root1:
            return root2
        if not root2:
            return root1

        def dfs(node1, node2):
            
            #If there are two nodes
            if not node1 and not node2:
                return None
            if not node1:
                return node2
            if not node2:
                return node1

            newNode = TreeNode(node1.val + node2.val)

            #Recursive
            newNode.left = dfs(node1.left if node1 else None, node2.left if node2 else None)
            newNode.right = dfs(node1.right if node1 else None, node2.right if node2 else None)
            
            return newNode

        return dfs(root1, root2)