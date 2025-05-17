# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        
        #Base Case
        if not head:
            return None
        if not head.next:
            return TreeNode(head.val)

        #Fast and Slow Pointer
        slow = head
        fast = head
        prev = None

        while fast and fast.next != None:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        #Cut the list to divide the list into two halves
        if prev:
            prev.next = None
        
        #Recursive
        root = TreeNode(slow.val) #Slow middle point
        root.left = self.sortedListToBST(head if slow != head else None)
        root.right = self.sortedListToBST(slow.next)

        return root