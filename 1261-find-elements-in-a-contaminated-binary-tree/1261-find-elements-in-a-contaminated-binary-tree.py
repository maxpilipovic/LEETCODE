# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.hashy = set()
        self.recover(root, 0)

    
    def recover(self, node, val):
        #If theres not something here
        if not node:
            return

        #Somehow add to hashy
        node.val = val
        self.hashy.add(val)
        
        #Change second and right
        self.recover(node.left, 2 * node.val + 1)
        self.recover(node.right, 2 * node.val + 2)

    def find(self, target: int) -> bool:
        return True if target in self.hashy else False
        


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)