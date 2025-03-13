# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        #Iterative DFS

        stack = [(root)]
        array = []

        while stack:

            node = stack.pop()

            array.append(node.val)

            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        
        #Sort
        array.sort()

        #Add each value to a new tree node
        dummy = TreeNode()
        curr = dummy

        for i in array:
            curr.right = TreeNode(i)
            curr = curr.right
        
        return dummy.right