# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        
        result = []

        if root is None:
            return result
        
        self.dfs(root, str(root.val), result)
        return result
        
    def dfs(self, node, current_path, result):

        if node.left is None and node.right is None:
            result.append(current_path)
            return

        if node.left is not None:
            self.dfs(node.left, current_path + '->' + str(node.left.val), result)

        if node.right is not None:
            self.dfs(node.right, current_path + '->' + str(node.right.val), result)

            