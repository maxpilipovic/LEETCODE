# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:

        my_dict = {}
        
        def dfs(node):
            #Base Case
            if not node:
                return 0
            
            #Recursive Case
            left = dfs(node.left)
            right = dfs(node.right)
            val = node.val + left + right

            if val in my_dict:
                my_dict[val] += 1
            else:
                my_dict[val] = 1

            return val
        
        dfs(root)

        max_freq = max(my_dict.values())

        return [key for key, value in my_dict.items() if max_freq == value]

        


            

            




        
        dfs(root)


            

