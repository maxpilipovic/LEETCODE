# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:

        dashes = 0
        stack = []
        i = 0

        while i < len(traversal):

            if traversal[i] == '-':
                dashes += 1
                i += 1
            else:
                j = i

                while j < len(traversal) and traversal[j] != '-':
                    j += 1
                
                num = int(traversal[i: j]) #Slicing
                node = TreeNode(num) #Change into node
                
                #Pop if length of stack is greater then dashes
                while len(stack) > dashes:
                    stack.pop()

                #Check left first
                if stack and not stack[-1].left:
                    stack[-1].left = node
                #Check right
                elif stack:
                    stack[-1].right = node

                stack.append(node)
                dashes = 0
                i = j

        return stack[0]











        


        