# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        
        if not root1 and not root2:
            return None
        #Create node
        newNode = TreeNode(0)

        def dfs(node1, node2, newNode):
            
            #If there are two nodes
            if node1 and node2:
                newNode.val = node1.val + node2.val
            elif node1 and not node2:
                newNode.val = node1.val
            elif not node1 and node2:
                newNode.val = node2.val
            else: 
                return None

            #Recursive

            #Check left
            if node1 and node1.left or node2 and node2.left:
                newNode.left = TreeNode(0)
                dfs(node1.left if node1 else None, node2.left if node2 else None, newNode.left)
            
            if node1 and node1.right or node2 and node2.right:
                newNode.right = TreeNode(0)
                dfs(node1.right if node1 else None, node2.right if node2 else None, newNode.right)
            
        dfs(root1, root2, newNode)

        return newNode