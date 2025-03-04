# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        
        if not nums:
            return None

        maxIndex = nums.index(max(nums))
        root = TreeNode(nums[maxIndex])

        #RECURSION LEFT
        root.left = self.constructMaximumBinaryTree(nums[:maxIndex])

        #RECURSION RIGHT
        root.right = self.constructMaximumBinaryTree(nums[maxIndex+1:])

        return root