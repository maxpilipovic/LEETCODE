# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        
        #Pointer to next node
        curr = node.next

        #Create a copy of this node
        node.val = curr.val

        #Move the pointer
        curr = curr.next
        node.next = curr



        

        