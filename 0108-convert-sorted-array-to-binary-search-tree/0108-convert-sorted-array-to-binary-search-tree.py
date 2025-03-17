# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        
        start = 0
        end = len(nums) - 1

        def bst(start, end):
            
            if start > end:
                return None
                
            #Find our midpoint
            mid = (start + end) // 2

            #Create a treenode
            node = TreeNode(nums[mid])

            #Recursivly call left and right
            node.left = bst(start, mid - 1)
            node.right = bst(mid + 1, end)

            return node
        

        return bst(start, end)